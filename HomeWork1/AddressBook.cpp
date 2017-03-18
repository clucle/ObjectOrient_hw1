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
    if (iOrder < m_pPerson.size()) 
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
        SortPerson();
        SavePerson();
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
	
	int state = 0;

	while (state > -1) {
        ClearScreen();
        if (state == 0) {
            ShowPerson();
        }

		int ichoice = CallMenu(state);

        if (state == 0) {
            // 메인화면
            if (ichoice == 0) break; // 종료
            if (ichoice == 1) state = 1; // 사람 추가
            if (ichoice == 2) state = 2; // 사람 삭제
            if (ichoice == 3) state = 3; // 관계 목록 추가
            if (ichoice == 4) state = 4; // 관계 목록 삭제
            if (ichoice == 5) state = 5; // 사람 검색
            if (ichoice == 6) state = 6;
        }
        else if (state == 1) {
            // 사람 추가 화면
            if (ichoice == 1) state = 0; //메인 화면으로 돌아감
        }
        else if (state == 2) {
            // 사람 삭제 화면
            if (ichoice == 0){
                state = 0;
            }
            if (ichoice == 1) state = 0; //메인 화면으로 돌아감
        }
        else if (state == 3) {
            // 관계 추가 화면
            if (ichoice == 1) state = 0;
        }
        else if (state == 4) {
            // 관계 삭제 화면
            if (ichoice == 1) state = 0;
        }
        else if (state == 5) {
            // 사람 검색 화면
            if (ichoice == 1) state = 0;
        }
        else if (state == 6) {
            // 사람 검색 화면
            if (ichoice == 1) state = 0;
        }
	}
}

int CAddressBook::CallMenu(int state)
{
	int result = 0;
    if (state == 0) {

        printf("\n- 당신의 선택 -\n");
        printf("   0 : 나가기\n");
        printf("   1 : 사람 추가\n");
        printf("   2 : 사람 삭제\n");
        printf("   3 : 관계 목록 추가\n");
        printf("   4 : 관계 목록 삭제\n");
        printf("   5 : 사람 검색\n");
        printf("   6 : 정보 수정\n");


        printf(" 선택해주세요 : ");

        cin >> result;
        if (SelectCorrect(result, 6)) return result;
    }
    else if (state == 1) {
        int num;
        string name = "", number = "", relation = "", Email = "";
        printf("\n");
        printf("이름을 입력해주세요 : ");
        cin >> name;
        printf("번호를 입력해주세요 : ");
        cin >> number;
        ShowRelation();
        printf("관계번호를 입력해주세요(숫자) 없을시 x입력 : ");
        if (m_sRelation.size() > 0) cin >> num;
        if (num < m_sRelation.size()) relation = m_sRelation[num];
        
        printf("Email 을 입력해주세요 없을시 x입력 : ");
        cin >> Email;

        AddPerson(name, number, relation, Email);
        return 1;
    }
    else if (state == 2) {
        printf("\n어떤방법으로 삭제하실건가요?\n");
        printf("0: 이름, 1: 전화번호, 2: 리스트로 삭제 :");

        int pick = 0;
        cin >> pick;

        if (!SelectCorrect(result, 2)) return 1; // error

        ShowPerson();

        string sInput;
        int iInput;

        if (pick == 0) {
            printf("\n지울 사람의 이름을 입력해주세요 : ");
            cin >> sInput;
            DelPerson_Name(sInput);
        }
        else if (pick == 1) {
            printf("\n지울 사람의 번호를 입력해주세요 : ");
            cin >> sInput;
            DelPerson_Pnumber(sInput);
        }
        else if (pick == 2) {
            printf("\n지울 사람의 리스트 번호를 입력해주세요 : ");
            cin >> iInput;
            DelPerson_Order(iInput);
        }
        SavePerson();
        return 1;
    }
    else if (state == 3) {
        ShowRelation();
        string sInput;
        printf("\n추가할 관계 목록을 적어주세요 : ");
        cin >> sInput;
        AddRelation(sInput);
        return 1;
    }
    else if (state == 4) {
        ShowRelation();
        string sInput;
        printf("\n삭제할 관계 목록을 적어주세요 : ");
        cin >> sInput;
        DelRelation(sInput);
        return 1;
    }
    else if (state == 5) {
        printf("\n어떤방법으로 검색하실건가요?\n");
        printf("0: 이름, 1: 전화번호, 2: 관계  로 검색 :");

        int pick = 0;
        cin >> pick;

        if (!SelectCorrect(result, 2)) return 1;


        if (pick < 2) {
            printf("검색할 단어의 일부 : ");
            string sFind;
            cin >> sFind;

            cout << "\n      연락처" << endl;
            printf("n 이름  번호        관계   이메일\n");
            int k = 0;
            CSearch mySearch;
            for (int i = 0; i < m_pPerson.size(); i++) {
                if (pick == 0 && mySearch.isSearched(m_pPerson[i].getName(), sFind)) {
                    cout << k << ' ';
                    cout << m_pPerson[i].getName() << ' ' << m_pPerson[i].getNumber() << ' ' <<
                        m_pPerson[i].getRelation() << ' ' << m_pPerson[i].getEmail() << endl;
                    k++;
                }
                if (pick == 1 && mySearch.isSearched(m_pPerson[i].getNumber(), sFind)) {
                    cout << k << ' ';
                    cout << m_pPerson[i].getName() << ' ' << m_pPerson[i].getNumber() << ' ' <<
                        m_pPerson[i].getRelation() << ' ' << m_pPerson[i].getEmail() << endl;
                    k++;
                }

            }

        }

        if (pick == 2) {
            int iRelation;
            ShowRelation();
            printf("관계 번호를 입력해주세요: ");
            cin >> iRelation;

            cout << "\n      연락처" << endl;
            printf("n 이름  번호        관계   이메일\n");
            int k = 0;
            for (int i = 0; i < m_pPerson.size(); i++) {
                if (m_pPerson[i].getRelation() == m_sRelation[iRelation]) {
                    cout << k << ' ';
                    cout << m_pPerson[i].getName() << ' ' << m_pPerson[i].getNumber() << ' ' <<
                        m_pPerson[i].getRelation() << ' ' << m_pPerson[i].getEmail() << endl;
                    k++;
                }
            }
        }
        
        printf("\n아무거나 입력하면 돌아갑니다.\n");

        string noProgress;
        cin >> noProgress;
        
        return 1;
    }
    else if (state == 6) {
        ShowPerson();
        printf("\n수정할 사람의 번호를 선택해주세요 : ");
        int iNum = 0;
        cin >> iNum;

        int iSelect;
        printf("수정할 것 선택해주세요\n");
        printf("  0: 이름 \n");
        printf("  1: 번호 \n");
        printf("  2: 관계 \n");
        printf("  3: Email \n");
        printf(" 선택 할 번호 : ");
        cin >> iSelect;

        string sChange;
        int iChange;
        
        ClearScreen();

        if (iSelect == 0) {
            printf("이름을 수정합니다\n");
            printf("수정 전 : ");
            cout << m_pPerson[iNum].getName() << endl;
            printf("수정 후 : ");
            cin >> sChange;
            m_pPerson[iNum].setName(sChange);
        }
        else if (iSelect == 1) {
            printf("번호를 수정합니다\n");
            printf("수정 전 : ");
            cout << m_pPerson[iNum].getNumber() << endl;
            printf("수정 후 : ");
            cin >> sChange;
            m_pPerson[iNum].setNumber(sChange);
        }
        else if (iSelect == 2) {
            printf("관계를 수정합니다\n");
            printf("수정 전 : ");
            cout << m_pPerson[iNum].getRelation() << endl;
            printf("수정 후 : ");
            ShowRelation();
            printf("수정 후 (숫자) // 없을시 x: ");
            cin >> iChange;

            if (iChange == 'x') m_pPerson[iNum].setRelation("");
            else m_pPerson[iNum].setRelation(m_sRelation[iChange]);
        }
        else if (iSelect == 3) {
            printf("Email을 수정합니다\n");
            printf("수정 전 : ");
            cout << m_pPerson[iNum].getEmail() << endl;
            printf("수정 후 : ");
            cin >> sChange;
            m_pPerson[iNum].setEmail(sChange);
        }
        SavePerson();
        return 1;
    }

	printf("wrong choice\n");
	CallMenu(state);
}
void CAddressBook::ShowPerson()
{
	cout << "      연락처" << endl;
	printf("n 이름  번호        관계   이메일\n");
	vector<CPerson>::iterator it = m_pPerson.begin();
    int k = 0;
	for (; it < m_pPerson.end(); it++) {
        cout << k << ' ';
		cout << it->getName() << ' ' << it->getNumber() <<' ' <<
			    it->getRelation() <<' '<< it->getEmail() <<endl;
        k++;
	}
    printf("------------------------------------");
}
void CAddressBook::ShowRelation()
{
	cout << " 관계 목록" << endl;
	for (int i = 0; i < m_sRelation.size(); i++) {
		cout << i << ". " << m_sRelation[i] << endl;
	}
}

void CAddressBook::MakeDir()
{
    char strFolderPath[] = { "\Data" };

    int nResult = _mkdir(strFolderPath);
}

bool CAddressBook::SelectCorrect(int num, int max)
{
    for (int i = 0; i <= max; i++) {
        if (i == num) return true;
    }
    return false;
}