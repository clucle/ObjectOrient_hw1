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
		//����ó�� ���� �����ش�. ���� ����Ʈ���� ����ó�� ���� �����ش�.
		pDevice->ShowPerson();
		
		printf("����� ���� 0 ������ 1 ��� �߰� 2 ��� ���� : \n");
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
				printf("1��:���踦 �����Ͻðڽ��ϱ�? \n2��:�̸����� �����Ͻðڽ��ϱ�?\n3��:�Ѵ� ����?");
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
					printf("1~3������ ���ڸ� �ٽ� ���ֽñ� �ٶ��ϴ�.\n");
			}
			pDevice->AddPerson(name, number, relation, email);
		}
		case 2:
		{
			int pick = 0;
			string Name;
			string PhoneNumber;
			string Order;
			printf("��ȭ ��ȣ ����Ʈ�� ���ϴ�\n");
			pDevice->ShowPerson();
			printf("�������� �����Ͻǰǰ���?\n");
			printf("1: �̸�, 2: ��ȭ��ȣ, 3: �ѹ� :");
			
			cin >> pick;
			
			switch (pick)
			{
			case 1:
				printf("������ ����ðڽ��ϱ�?");
				cin >> Name;
				pDevice->DelPerson_Name(Name);
				break;
			case 2:
				printf("������ ����ðڽ��ϱ�?");
				cin >> PhoneNumber;
				pDevice->DelPerson_Pnumber(PhoneNumber);
				break;
			case 3:
				printf("�� ��°�� ����ðڽ��ϱ�?");
				cin >> Order;
				pDevice->DelPerson_Order(Order);
			default:
				printf("1~3������ ���ڸ� ���ּ���");
				break;
			}
		}
		
		default:
			//printf("0~?������ ���ڸ� ġ����);
			break;
	}
		}	
    delete pDevice;
    return 0;
}