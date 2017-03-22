#include "AddressBook.h"
using namespace std;

int ScreenMainMenu();

int main() {
    CAddressBook* pDevice = new CAddressBook();
	
    // Load Data, Clear Screen
    pDevice->Init();

    /* CallMenu return state */
    // User Define at ScreenMainMenu()
    // 0: Exit
    // 1: Add Person
    // 2: Del Person
    // 3: Add Relation
    // 4: Del Relation
    // 5: Search Person
    // 6: Modify Info
    // 7: watch SMS
    /* ===================== */
    int iState = 0;
    int iChoice = 0;

    while (iState > -1) {
        // Show AddressBook
        pDevice->DoShowPerson();
        int iChoice = ScreenMainMenu();

        switch (iChoice) {
        case 0:
            iState = -1;
            break;
        case 1:
            pDevice->DoAddPerson();
            break;
        case 2:
            pDevice->DoDelPerson();
            break;
        case 3:
            pDevice->DoAddRelation();
            break;
        case 4:
            pDevice->DoDelRelation();
            break;
        case 5:
            pDevice->DoSearchPerson();
            break;
        case 6:
            pDevice->DoModifyPerson();
            break;
        case 7:
            pDevice->DoWatchSMS();
            break;
        default:
            printf("Error!");
            iState = -1;
            break;
        }

        if (iState != -1) iState = 0;
    }

    

    delete pDevice;
    return 0;
}

int ScreenMainMenu() {
    int result = 0;
    int nMenu = 8;
    printf("\n- ����� ���� -\n");
    printf("   0 : ������\n");
    printf("   1 : ��� �߰�\n");
    printf("   2 : ��� ����\n");
    printf("   3 : ���� ��� �߰�\n");
    printf("   4 : ���� ��� ����\n");
    printf("   5 : ��� �˻�\n");
    printf("   6 : ���� ����\n");
    printf("   7 : SMS ����\n");

    printf(" �������ּ��� : ");

    cin >> result;

    for (int i = 0; i < nMenu; i++) {
        if (i == result) return result;
    }
    return -1;
}