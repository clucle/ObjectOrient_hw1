#include "AddressBook.h"
using namespace std;
int main() {
    CAddressBook* pDevice = new CAddressBook();
	
	int state = 0;
	while (1) {
		printf("����� ���� 0 ������ 1 ��� �߰� : ");
		scanf("%d", &state);

		if (!state) break;

	}
		
	for (int i =0;i<10;i++)
	{
		pDevice->AddPerson()
	}
    delete pDevice;
    return 0;
}