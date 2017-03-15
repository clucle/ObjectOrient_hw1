#include "AddressBook.h"
using namespace std;
int main() {
    CAddressBook* pDevice = new CAddressBook();
	
	int state = 1;
	string name;
	string number;
	string relation;
	string email;
	// basic addperson
	while (state) {
		//연락처를 먼저 보여준다. 보통 스마트폰이 연락처를 먼저 보여준다.
		pDevice->ShowPerson();
		
		printf("당신의 선택 0 나가기 1 사람 추가 2 사람 삭제 : \n");
		scanf("%d", &state);

		switch (state)
		{
		case 0:
			break;
		case 1:
		{
			cin >> name;
			cin >> number;
			while (1)
			{
				printf("1번:관계를 생성하시겠습니까? \n2번:이메일을 생성하시겠습니까?\n3번:둘다 생성?");
				scanf("%d", &state);
				if (state == 1)
					cin >> relation; break;
				if (state == 2)
					cin >> email; break;
				if (state == 3)
				{
					cin >> relation;
					cin >> email;
					break;
				}
				else
					printf("1~3까지의 숫자를 다시 쳐주시길 바랍니다.\n");
			}
			pDevice->AddPerson(name, number, relation, email);
		}
		case 2:
		{
			int pick = 0;
			string Name;
			string PhoneNumber;
			string Order;
			printf("전화 번호 리스트를 봅니다\n");
			pDevice->ShowPerson();
			printf("어떤방법으로 삭제하실건가요?\n");
			printf("1: 이름, 2: 전화번호, 3: 넘버 :");
			
			cin >> pick;
			
			switch (pick)
			{
			case 1:
				printf("누구를 지우시겠습니까?");
				cin >> Name;
				pDevice->DelPerson_Name(Name);
				break;
			case 2:
				printf("누구를 지우시겠습니까?");
				cin >> PhoneNumber;
				pDevice->DelPerson_Pnumber(PhoneNumber);
				break;
			case 3:
				printf("몇 번째를 지우시겠습니까?");
				cin >> Order;
				pDevice->DelPerson_Order(Order);
			default:
				printf("1~3까지의 숫자를 쳐주세요");
				break;
			}
		}
		
		default:
			//printf("0~?까지의 숫자를 치세요);
			break;
	}
		}	
    delete pDevice;
    return 0;
}