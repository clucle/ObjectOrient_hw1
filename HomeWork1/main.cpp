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
    printf("\n- 당신의 선택 -\n");
    printf("   0 : 나가기\n");
    printf("   1 : 사람 추가\n");
    printf("   2 : 사람 삭제\n");
    printf("   3 : 관계 목록 추가\n");
    printf("   4 : 관계 목록 삭제\n");
    printf("   5 : 사람 검색\n");
    printf("   6 : 정보 수정\n");
    printf("   7 : SMS 보기\n");

    printf(" 선택해주세요 : ");

    cin >> result;

    for (int i = 0; i < nMenu; i++) {
        if (i == result) return result;
    }
    return -1;
}