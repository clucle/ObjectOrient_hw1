#include "AddressBook.h"


CAddressBook::CAddressBook()
{
    m_nRelation = 20;
}


CAddressBook::~CAddressBook()
{

}

void CAddressBook::Init()
{
    MakeDir();
    LoadPerson();
    LoadRelation();
    LoadSMS();
    ClearScreen();
}

// 유저 접근 (기능 단위 Do)
void CAddressBook::DoAddPerson()
{
    int num;
    string name = "", number = "", relation = "", Email = "";
    printf("\n");
    printf("이름을 입력해주세요 : ");
    std::cin >> name;
    printf("번호를 입력해주세요 : ");
    std::cin >> number;
    ShowRelation();
    printf("관계번호를 입력해주세요(숫자) 없을시 x입력 : ");
    if (m_sRelation.size() > 0) std::cin >> relation;
    if (relation != "x") {
        num = atoi(relation.c_str());
        if (SelectCorrect(num, (int)m_sRelation.size() - 1)) relation = m_sRelation[num];
    }


    printf("Email 을 입력해주세요 없을시 x입력 : ");
    std::cin >> Email;

    AddPerson(name, number, relation, Email);
    SavePerson();
}

void CAddressBook::DoDelPerson()
{
    printf("\n어떤방법으로 삭제하실건가요?\n");
    printf("0: 이름, 1: 전화번호, 2: 리스트로 삭제 :");

    int pick = 0;
    std::cin >> pick;

    if (!SelectCorrect(pick, 2)) return ; // error

    ShowPerson();

    string sInput;
    int iInput;

    if (pick == 0) {
        printf("\n지울 사람의 이름을 입력해주세요 : ");
        std::cin >> sInput;
        DelPersonName(sInput);
    }
    else if (pick == 1) {
        printf("\n지울 사람의 번호를 입력해주세요 : ");
        std::cin >> sInput;
        DelPersonNumber(sInput);
    }
    else if (pick == 2) {
        printf("\n지울 사람의 리스트 번호를 입력해주세요 : ");
        std::cin >> iInput;
        DelPersonOrder(iInput);
    }
    SavePerson();
}

void CAddressBook::DoAddRelation()
{
    ShowRelation();
    string sInput;
    printf("\n추가할 관계 목록을 적어주세요 : ");
    std::cin >> sInput;
    AddRelation(sInput);
}

void CAddressBook::DoDelRelation()
{
    ShowRelation();
    string sInput;
    printf("\n삭제할 관계 목록을 적어주세요 : ");
    std::cin >> sInput;
    DelRelation(sInput);
}

void CAddressBook::DoSearchPerson()
{
    printf("\n어떤방법으로 검색하실건가요?\n");
    printf("0: 이름, 1: 전화번호, 2: 관계  로 검색 :");

    int pick = 0;
    std::cin >> pick;

    if (!SelectCorrect(pick, 2)) return ;
    
    if (pick == 1) 

    if (pick < 2) {
        printf("검색할 단어의 일부 : ");
        string sFind;
        std::cin >> sFind;
        cout << "\n      연락처" << endl;
        printf("n 이름  번호        관계   이메일\n");

        if (pick == 0) SearchPersonName(sFind);
        if (pick == 1) SearchPersonNumber(sFind);
    }

    if (pick == 2) {
        int iRelation;
        ShowRelation();
        printf("관계 번호를 입력해주세요: ");
        std::cin >> iRelation;

        SearchPersonRelation(iRelation);

        cout << "\n      연락처" << endl;
        printf("n 이름  번호        관계   이메일\n");
    }

    printf("\n아무값이나 입력하면 돌아갑니다.\n");

    string noProgress;
    std::cin >> noProgress;
}

void CAddressBook::DoModifyPerson()
{
    ShowPerson();
    printf("\n수정할 사람의 번호를 선택해주세요 : ");
    int iNum = 0;
    std::cin >> iNum;

    int iSelect;
    printf("수정할 것 선택해주세요\n");
    printf("  0: 이름 \n");
    printf("  1: 번호 \n");
    printf("  2: 관계 \n");
    printf("  3: Email \n");
    printf(" 선택 할 번호 : ");
    std::cin >> iSelect;

    string sChange;

    ClearScreen();

    if (iSelect == 0) ModifyPersonName(iNum);
    else if (iSelect == 1) ModifyPersonNumber(iNum);
    else if (iSelect == 2) ModifyPersonRelation(iNum);
    else if (iSelect == 3) ModifyPersonEmail(iNum);

    SavePerson();
}

void CAddressBook::DoWatchSMS()
{
    printf(" 당신의 선택 \n");
    printf(" 0: 리스트내역으로 보기\n");
    printf(" 1: 보낸사람번호로 검색하기\n");
    printf(" 2: 받은사람번호로 검색하기\n");
    printf(" 선택해주세요 : ");
    int iSelect;
    std::cin >> iSelect;

    switch (iSelect) {
    case 0:
        WatchSMSOrder();
        break;
    case 1:
        WatchSMSSender();
        break;
    case 2:
        WatchSMSReceiver();
        break;
    }
    printf("아무거나 입력하시면 돌아갑니다.");
    std::cin >> iSelect;
}

void CAddressBook::DoShowPerson()
{
    ShowPerson();
}



// 주요 기능 처리
void CAddressBook::AddPerson(string sName, string sNumber, string sRelation, string sEmail)
{
    CPerson NewPerson(sName, sNumber);
    if (sRelation != "x") NewPerson.setRelation(sRelation);
    if (sEmail != "x")    NewPerson.setEmail(sEmail);
    m_pPerson.push_back(NewPerson);
}

void CAddressBook::DelPersonName(string sName)
{
    // 이름으로 삭제
    for (int i = 0; i < m_pPerson.size(); i++) {
        if (m_pPerson[i].getName() == sName) {
            m_pPerson.erase(m_pPerson.begin() + i);
            break;
        }
    }
}
void CAddressBook::DelPersonNumber(string sNumber)
{
    // 번호로 삭제
    for (int i = 0; i < m_pPerson.size(); i++) {
        if (m_pPerson[i].getNumber() == sNumber) {
            m_pPerson.erase(m_pPerson.begin() + i);
            break;
        }
    }
}
void CAddressBook::DelPersonOrder(int iOrder)
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

void CAddressBook::SearchPersonName(string sName)
{
    int k = 0;
    CSearch mySearch;
    for (int i = 0; i < m_pPerson.size(); i++) {
        if (mySearch.isSearched(m_pPerson[i].getName(), sName)) {
            cout << k << ' ';
            cout << m_pPerson[i].getName() << ' ' << m_pPerson[i].getNumber() << ' ' <<
                m_pPerson[i].getRelation() << ' ' << m_pPerson[i].getEmail() << endl;
            k++;
        }
    }
}
void CAddressBook::SearchPersonNumber(string sNumber)
{
    int k = 0;
    CSearch mySearch;
    for (int i = 0; i < m_pPerson.size(); i++) {
        if (mySearch.isSearched(m_pPerson[i].getNumber(), sNumber)) {
            cout << k << ' ';
            cout << m_pPerson[i].getName() << ' ' << m_pPerson[i].getNumber() << ' ' <<
                m_pPerson[i].getRelation() << ' ' << m_pPerson[i].getEmail() << endl;
            k++;
        }
    }
}
void CAddressBook::SearchPersonRelation(int iRelation)
{
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

void CAddressBook::ModifyPersonName(int iNum)
{
    printf("이름을 수정합니다\n");
    printf("수정 전 : ");
    cout << m_pPerson[iNum].getName() << endl;
    printf("수정 후 : ");
    string sChange;
    std::cin >> sChange;
    m_pPerson[iNum].setName(sChange);
}
void CAddressBook::ModifyPersonNumber(int iNum)
{
    printf("번호를 수정합니다\n");
    printf("수정 전 : ");
    cout << m_pPerson[iNum].getNumber() << endl;
    printf("수정 후 : ");
    string sChange;
    std::cin >> sChange;
    m_pPerson[iNum].setNumber(sChange);
}
void CAddressBook::ModifyPersonRelation(int iNum)
{
    printf("관계를 수정합니다\n");
    printf("수정 전 : ");
    cout << m_pPerson[iNum].getRelation() << endl;
    printf("수정 후 : ");
    ShowRelation();
    printf("수정 후 (숫자) // 없을시 x: ");
    int iChange;
    std::cin >> iChange;

    if (iChange == 'x') m_pPerson[iNum].setRelation("");
    else m_pPerson[iNum].setRelation(m_sRelation[iChange]);
}
void CAddressBook::ModifyPersonEmail(int iNum)
{
    printf("Email을 수정합니다\n");
    printf("수정 전 : ");
    cout << m_pPerson[iNum].getEmail() << endl;
    printf("수정 후 : ");
    string sChange;
    std::cin >> sChange;
    m_pPerson[iNum].setEmail(sChange);
}

void CAddressBook::WatchSMSOrder()
{
    ShowSMS();
    printf("보고싶은 내용의 번호를 써주세요(숫자) :");
    int iSelect;
    std::cin >> iSelect;
    ClearScreen();
    if (iSelect < m_pSMS.size()) {
        cout << "보낸사람 : " << m_pSMS[iSelect].getSender() << endl;
        for (int i = 0; i < m_pPerson.size(); i++) {
            if (m_pPerson[i].getNumber() == m_pSMS[iSelect].getSender()) {
                cout << "# 이름 : " << m_pPerson[i].getName() <<
                    " 관계 : " << m_pPerson[i].getRelation() << endl;
            }
        }
        cout << "받는사람 : " << m_pSMS[iSelect].getReceiver() << endl;
        for (int i = 0; i < m_pPerson.size(); i++) {
            if (m_pPerson[i].getNumber() == m_pSMS[iSelect].getReceiver()) {
                cout << "# 이름 : " << m_pPerson[i].getName() <<
                    " 관계 : " << m_pPerson[i].getRelation() << endl;
            }
        }
        cout << "내용 : " << m_pSMS[iSelect].getContent() << endl;
    }
}

void CAddressBook::WatchSMSSender()
{
    printf("검색할 핸드폰 번호를 입력해주세요 : ");
    string sNumber;
    std::cin >> sNumber;
    printf("----- 이 번호로 보낸 내역 -----\n");
    for (int i = 0; i < m_pSMS.size(); i++) {

        if (m_pSMS[i].getSender() == sNumber) {
            cout << "받은사람 번호: " << m_pSMS[i].getReceiver() << endl;
            for (int k = 0; k < m_pPerson.size(); k++) {
                if (m_pPerson[k].getNumber() == m_pSMS[i].getReceiver()) {
                    cout << "# 받은사람 이름 : " << m_pPerson[i].getName() <<
                        " 관계 : " << m_pPerson[i].getRelation() << endl;
                }
            }
            cout << "내용 : " << m_pSMS[i].getContent() << endl;
        }
    }
}

void CAddressBook::WatchSMSReceiver()
{
    printf("검색할 핸드폰 번호를 입력해주세요 : ");
    string sNumber;
    std::cin >> sNumber;
    printf("----- 이 번호로 받은 내역 -----\n");
    for (int i = 0; i < m_pSMS.size(); i++) {
        if (m_pSMS[i].getReceiver() == sNumber) {

            cout << "보낸사람 번호: " << m_pSMS[i].getSender() << endl;
            for (int k = 0; k < m_pPerson.size(); k++) {
                if (m_pPerson[k].getNumber() == m_pSMS[i].getSender()) {
                    cout << "# 보낸사람 이름 : " << m_pPerson[k].getName() <<
                        " 관계 : " << m_pPerson[k].getRelation() << endl;
                }
            }
            cout << "내용 : " << m_pSMS[i].getContent() << endl;
        }
    }
}

// 내부 로직 처리
void CAddressBook::MakeDir()
{
    char strFolderPath[] = { "Data" };
    int nResult = _mkdir(strFolderPath);
    char strFolderPath2[] = { "Data\\SMS" };
    nResult = _mkdir(strFolderPath2);
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

void CAddressBook::LoadSMS()
{
    for (int i = 1; i < 21; i++) {
        /* SMS 불러오기 */
        ifstream fin_entry("Data/SMS/SMS" + to_string(i) + ".txt");
        char receive[1024];


        if (fin_entry.is_open()) {
            string sSender;
            string sReceiver;
            string sContent = "";

            int nCount = 0;

            while (fin_entry.getline(receive, sizeof(receive)))
            {
                if (nCount == 0) sSender = receive;
                if (nCount == 1) sReceiver = receive;
                if (nCount > 1) sContent += receive;
                nCount++;
            }

            CSMS sms(sSender, sReceiver, sContent);
            m_pSMS.push_back(sms);
        }
    }
}

void CAddressBook::SavePerson()
{
    ofstream fout;
    fout.open("Data/Entry.txt");

    SortPerson();

    for (int i = 0; i < m_pPerson.size(); i++) {
        fout << m_pPerson[i].getName() << "&*(";
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

bool CAddressBook::SelectCorrect(int num, int max)
{
    for (int i = 0; i <= max; i++) {
        if (i == num) return true;
    }
    return false;
}

void CAddressBook::ShowPerson()
{
    cout << "      연락처" << endl;
    printf("n 이름  번호        관계   이메일\n");
    vector<CPerson>::iterator it = m_pPerson.begin();
    int k = 0;
    for (; it < m_pPerson.end(); it++) {
        cout << k << ' ';
        cout << it->getName() << ' ' << it->getNumber() << ' ' <<
            it->getRelation() << ' ' << it->getEmail() << endl;
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
void CAddressBook::ShowSMS()
{
    cout << " SMS 목록" << endl;
    for (int i = 0; i < m_pSMS.size(); i++) {
        cout << i << ". "
            << "보낸사람 : " << m_pSMS[i].getSender()
            << " 받은사람 : " << m_pSMS[i].getReceiver() << endl;
    }
}
