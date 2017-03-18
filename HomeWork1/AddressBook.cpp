#include "AddressBook.h"


CAddressBook::CAddressBook()
{

}


CAddressBook::~CAddressBook()
{

}

void CAddressBook::AddPerson(string sName, string sNumber, string sRelation, string sEmail)
{
	CPerson NewPerson(sName, sNumber);
	if (sRelation != "x") NewPerson.setRelation(sRelation);
    if (sEmail != "x")    NewPerson.setEmail(sEmail);
	m_pPerson.push_back(NewPerson);
    SavePerson();
}

void CAddressBook::DelPerson_Name(string sName)
{
    // 이름으로 삭제
	for (int i = 0; i < m_pPerson.size(); i++) {
		if (m_pPerson[i].getName() == sName) {
			m_pPerson.erase(m_pPerson.begin() + i);
			break;
		}
	}
}
void CAddressBook::DelPerson_Pnumber(string sNumber)
{
    // 번호로 삭제
	for (int i = 0; i < m_pPerson.size(); i++) {
		if (m_pPerson[i].getNumber() == sNumber) {
			m_pPerson.erase(m_pPerson.begin() + i);
			break;
		}
	}
}
void CAddressBook::DelPerson_Order(int iOrder)
{
    // 순서로 삭제
	m_pPerson.erase(m_pPerson.begin() + iOrder);
}
void CAddressBook::AddRelation(string sName)
{
    if (m_sRelation.size() > m_nRelation) {
        // error over maxcount list
    }
    else {
        if (sName != "") {
            vector<string>::iterator it;
            it = find(m_sRelation.begin(), m_sRelation.end(), sName);
            if (it != m_sRelation.end())
            {
                // error same Relation
            }
            else {
                m_sRelation.push_back(sName);
                SaveRelation();
            }
        }
        else {
            // error non blank plz
        }
    }
}

void CAddressBook::DelRelation(string sName)
{
    if (sName != "") {
        vector<string>::iterator it;
        it = find(m_sRelation.begin(), m_sRelation.end(), sName);
        if (it != m_sRelation.end())
        {
            m_sRelation.erase(it);
            SaveRelation();
        }
        else {
            // error can't find
        }

    }
    else {
        // error non blank plz
    }
}

void CAddressBook::LoadPerson()
{
    /* 사람 관련 불러오기 */
    ifstream fin_entry("Data/Entry.txt");
    char receive[100];

    if (fin_entry.is_open()) {
        string sName;
        string sNumber;
        string sRelation = "";
        string sEmail = "";
        // 파일 있을 시 정보 불러오기
        while (fin_entry.getline(receive, sizeof(receive)))
        {
            sRelation = "";
            sEmail = "";

            int count = 0;
            char *context = NULL;
            char *ptr = strtok_s(receive, "&*(", &context);      // " " 공백 문자를 기준으로 문자열을 자름, 포인터 반환

            while (ptr != NULL)               // 자른 문자열이 나오지 않을 때까지 반복
            {
                if (count == 0) sName = ptr;
                if (count == 1) sNumber = ptr;
                if (count == 2) sRelation = ptr;
                if (count == 3) sEmail = ptr;

                count++;
                ptr = strtok_s(NULL, "&*(", &context);      // 다음 문자열을 잘라서 포인터를 반환
            }
            CPerson person(sName, sNumber);
            if (sRelation != "") person.setRelation(sRelation);
            if (sEmail != "") person.setEmail(sEmail);

            m_pPerson.push_back(person);
        }        
    }
    else {
        // 파일 없을 시 새로운 파일 생성
        ofstream outputFile("Data/Entry.txt");
    }
}
void CAddressBook::LoadRelation()
{
    /* 관계 관련 불러오기 */
    ifstream fin_relation("Data/Relation.txt");
    char receive[100];

    if (fin_relation.is_open()) {
        // 파일 있을 시 정보 불러오기
        while (fin_relation.getline(receive, sizeof(receive)))
        {
            m_sRelation.push_back(receive);
        }
    }
    else {
        // 파일 없을 시 새로운 파일 생성
        ofstream outputFile("Data/Relation.txt");
    }
}

void CAddressBook::SavePerson()
{
    ofstream fout;
    fout.open("Data/Entry.txt");

    SortPerson();

    for (int i = 0; i < m_pPerson.size(); i++) {
        fout << m_pPerson[i].getName()  << "&*(";
        fout << m_pPerson[i].getNumber() << "&*(";
        fout << m_pPerson[i].getRelation() << "&*(";
        fout << m_pPerson[i].getEmail() << endl;
    }
    
    fout.close();
}
void CAddressBook::SaveRelation()
{
    ofstream fout;
    fout.open("Data/Relation.txt");

    for (int i = 0; i < m_sRelation.size(); i++) {
        fout << m_sRelation[i] << endl;
    }

    fout.close();
}

void CAddressBook::SortPerson()
{
    sort(m_pPerson.begin(), m_pPerson.end());
}

void CAddressBook::Search()
{
}

void CAddressBook::Run()
{
    MakeDir();
	LoadPerson();
	LoadRelation();
	
	// 1 : 초기 화면
    // 2 : 사람 추가

	int state = 1;

	while (state > 0) {
        if (state == 1) {
            ShowPerson();
        }

		int ichoice = CallMenu(state);

        if (state == 1) {
            if (ichoice == 0) break; // 종료
            if (ichoice == 1) state = 2; // 사람 추가
        }
        else if (state == 2) {
            if (ichoice == 1) state = 1; //메인 화면으로 돌아감
        }
        ClearScreen();
	}
	/*
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
		scanf_s("%d", &state);

		switch (state)
		{
		case 0:
			break;
		case 1:
		{
			
		}
		case 2:
		{
			int pick = 0;
			string Name;
			string PhoneNumber;
			int Order;
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
				pDevice->DelPerson_Order(Order - 1);
				break;
			default:
				printf("1~3까지의 숫자를 쳐주세요");
				break;
			}
		}

		default:
			//printf("0~?까지의 숫자를 치세요);
			break;
		}
	}*/
}

int CAddressBook::CallMenu(int state)
{
	int result = 0;
    if (state == 1) {

        printf("\n- 당신의 선택 -\n");
        printf("   0 : 나가기\n");
        printf("   1 : 사람 추가\n");
        printf("   2 : 사람 삭제\n");
        printf(" 선택해주세요 : ");

        cin >> result;
        if (result >= 0 && result < 3) return result;
    }
    else if (state == 2) {
        string name = "", number = "", relation = "", Email = "";

        printf("이름을 입력해주세요 : ");
        cin >> name;
        printf("번호를 입력해주세요 : ");
        cin >> number;
        ShowRelation();
        printf("관계를 입력해주세요 없을시 x입력 : ");
        cin >> relation;
        printf("Email 을 입력해주세요 없을시 x입력 : ");
        cin >> Email;

        AddPerson(name, number, relation, Email);
        return 1;
    }
	printf("wrong choice\n");
	CallMenu(state);
}
void CAddressBook::ShowPerson()
{
	cout << "      연락처" << endl;
	printf("이름  번호        관계   이메일\n");
	vector<CPerson>::iterator it = m_pPerson.begin();
	for (; it < m_pPerson.end(); it++) {
		cout << it->getName()<< ' ' << it->getNumber()<<' ' <<
			    it->getRelation()<<' '<< it->getEmail()<<endl;
	}
    printf("------------------------------------");
}
void CAddressBook::ShowRelation()
{
	cout << " 관계 목록" << endl;
	for (int i = 0; i < m_sRelation.size(); i++) {
		cout << i << "." << m_sRelation[i] << endl;
	}
}

void CAddressBook::MakeDir()
{
    char strFolderPath[] = { "\Data" };

    int nResult = _mkdir(strFolderPath);
}