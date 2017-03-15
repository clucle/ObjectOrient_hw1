#include "AddressBook.h"
using namespace std;
int main() {
    CAddressBook* pDevice = new CAddressBook();
	
	int state = 0;
	while (1) {
		printf("당신의 선택 0 나가기 1 사람 추가 : ");
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