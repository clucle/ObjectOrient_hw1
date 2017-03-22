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

// ���� ���� (��� ���� Do)
void CAddressBook::DoAddPerson()
{
    int num;
    string name = "", number = "", relation = "", Email = "";
    printf("\n");
    printf("�̸��� �Է����ּ��� : ");
    std::cin >> name;
    printf("��ȣ�� �Է����ּ��� : ");
    std::cin >> number;
    ShowRelation();
    printf("�����ȣ�� �Է����ּ���(����) ������ x�Է� : ");
    if (m_sRelation.size() > 0) std::cin >> relation;
    if (relation != "x") {
        num = atoi(relation.c_str());
        if (SelectCorrect(num, (int)m_sRelation.size() - 1)) relation = m_sRelation[num];
    }


    printf("Email �� �Է����ּ��� ������ x�Է� : ");
    std::cin >> Email;

    AddPerson(name, number, relation, Email);
    SavePerson();
}

void CAddressBook::DoDelPerson()
{
    printf("\n�������� �����Ͻǰǰ���?\n");
    printf("0: �̸�, 1: ��ȭ��ȣ, 2: ����Ʈ�� ���� :");

    int pick = 0;
    std::cin >> pick;

    if (!SelectCorrect(pick, 2)) return ; // error

    ShowPerson();

    string sInput;
    int iInput;

    if (pick == 0) {
        printf("\n���� ����� �̸��� �Է����ּ��� : ");
        std::cin >> sInput;
        DelPersonName(sInput);
    }
    else if (pick == 1) {
        printf("\n���� ����� ��ȣ�� �Է����ּ��� : ");
        std::cin >> sInput;
        DelPersonNumber(sInput);
    }
    else if (pick == 2) {
        printf("\n���� ����� ����Ʈ ��ȣ�� �Է����ּ��� : ");
        std::cin >> iInput;
        DelPersonOrder(iInput);
    }
    SavePerson();
}

void CAddressBook::DoAddRelation()
{
    ShowRelation();
    string sInput;
    printf("\n�߰��� ���� ����� �����ּ��� : ");
    std::cin >> sInput;
    AddRelation(sInput);
}

void CAddressBook::DoDelRelation()
{
    ShowRelation();
    string sInput;
    printf("\n������ ���� ����� �����ּ��� : ");
    std::cin >> sInput;
    DelRelation(sInput);
}

void CAddressBook::DoSearchPerson()
{
    printf("\n�������� �˻��Ͻǰǰ���?\n");
    printf("0: �̸�, 1: ��ȭ��ȣ, 2: ����  �� �˻� :");

    int pick = 0;
    std::cin >> pick;

    if (!SelectCorrect(pick, 2)) return ;
    
    if (pick == 1) 

    if (pick < 2) {
        printf("�˻��� �ܾ��� �Ϻ� : ");
        string sFind;
        std::cin >> sFind;
        cout << "\n      ����ó" << endl;
        printf("n �̸�  ��ȣ        ����   �̸���\n");

        if (pick == 0) SearchPersonName(sFind);
        if (pick == 1) SearchPersonNumber(sFind);
    }

    if (pick == 2) {
        int iRelation;
        ShowRelation();
        printf("���� ��ȣ�� �Է����ּ���: ");
        std::cin >> iRelation;

        SearchPersonRelation(iRelation);

        cout << "\n      ����ó" << endl;
        printf("n �̸�  ��ȣ        ����   �̸���\n");
    }

    printf("\n�ƹ����̳� �Է��ϸ� ���ư��ϴ�.\n");

    string noProgress;
    std::cin >> noProgress;
}

void CAddressBook::DoModifyPerson()
{
    ShowPerson();
    printf("\n������ ����� ��ȣ�� �������ּ��� : ");
    int iNum = 0;
    std::cin >> iNum;

    int iSelect;
    printf("������ �� �������ּ���\n");
    printf("  0: �̸� \n");
    printf("  1: ��ȣ \n");
    printf("  2: ���� \n");
    printf("  3: Email \n");
    printf(" ���� �� ��ȣ : ");
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
    printf(" ����� ���� \n");
    printf(" 0: ����Ʈ�������� ����\n");
    printf(" 1: ���������ȣ�� �˻��ϱ�\n");
    printf(" 2: ���������ȣ�� �˻��ϱ�\n");
    printf(" �������ּ��� : ");
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
    printf("�ƹ��ų� �Է��Ͻø� ���ư��ϴ�.");
    std::cin >> iSelect;
}

void CAddressBook::DoShowPerson()
{
    ShowPerson();
}



// �ֿ� ��� ó��
void CAddressBook::AddPerson(string sName, string sNumber, string sRelation, string sEmail)
{
    CPerson NewPerson(sName, sNumber);
    if (sRelation != "x") NewPerson.setRelation(sRelation);
    if (sEmail != "x")    NewPerson.setEmail(sEmail);
    m_pPerson.push_back(NewPerson);
}

void CAddressBook::DelPersonName(string sName)
{
    // �̸����� ����
    for (int i = 0; i < m_pPerson.size(); i++) {
        if (m_pPerson[i].getName() == sName) {
            m_pPerson.erase(m_pPerson.begin() + i);
            break;
        }
    }
}
void CAddressBook::DelPersonNumber(string sNumber)
{
    // ��ȣ�� ����
    for (int i = 0; i < m_pPerson.size(); i++) {
        if (m_pPerson[i].getNumber() == sNumber) {
            m_pPerson.erase(m_pPerson.begin() + i);
            break;
        }
    }
}
void CAddressBook::DelPersonOrder(int iOrder)
{
    // ������ ����
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
    printf("�̸��� �����մϴ�\n");
    printf("���� �� : ");
    cout << m_pPerson[iNum].getName() << endl;
    printf("���� �� : ");
    string sChange;
    std::cin >> sChange;
    m_pPerson[iNum].setName(sChange);
}
void CAddressBook::ModifyPersonNumber(int iNum)
{
    printf("��ȣ�� �����մϴ�\n");
    printf("���� �� : ");
    cout << m_pPerson[iNum].getNumber() << endl;
    printf("���� �� : ");
    string sChange;
    std::cin >> sChange;
    m_pPerson[iNum].setNumber(sChange);
}
void CAddressBook::ModifyPersonRelation(int iNum)
{
    printf("���踦 �����մϴ�\n");
    printf("���� �� : ");
    cout << m_pPerson[iNum].getRelation() << endl;
    printf("���� �� : ");
    ShowRelation();
    printf("���� �� (����) // ������ x: ");
    int iChange;
    std::cin >> iChange;

    if (iChange == 'x') m_pPerson[iNum].setRelation("");
    else m_pPerson[iNum].setRelation(m_sRelation[iChange]);
}
void CAddressBook::ModifyPersonEmail(int iNum)
{
    printf("Email�� �����մϴ�\n");
    printf("���� �� : ");
    cout << m_pPerson[iNum].getEmail() << endl;
    printf("���� �� : ");
    string sChange;
    std::cin >> sChange;
    m_pPerson[iNum].setEmail(sChange);
}

void CAddressBook::WatchSMSOrder()
{
    ShowSMS();
    printf("������� ������ ��ȣ�� ���ּ���(����) :");
    int iSelect;
    std::cin >> iSelect;
    ClearScreen();
    if (iSelect < m_pSMS.size()) {
        cout << "������� : " << m_pSMS[iSelect].getSender() << endl;
        for (int i = 0; i < m_pPerson.size(); i++) {
            if (m_pPerson[i].getNumber() == m_pSMS[iSelect].getSender()) {
                cout << "# �̸� : " << m_pPerson[i].getName() <<
                    " ���� : " << m_pPerson[i].getRelation() << endl;
            }
        }
        cout << "�޴»�� : " << m_pSMS[iSelect].getReceiver() << endl;
        for (int i = 0; i < m_pPerson.size(); i++) {
            if (m_pPerson[i].getNumber() == m_pSMS[iSelect].getReceiver()) {
                cout << "# �̸� : " << m_pPerson[i].getName() <<
                    " ���� : " << m_pPerson[i].getRelation() << endl;
            }
        }
        cout << "���� : " << m_pSMS[iSelect].getContent() << endl;
    }
}

void CAddressBook::WatchSMSSender()
{
    printf("�˻��� �ڵ��� ��ȣ�� �Է����ּ��� : ");
    string sNumber;
    std::cin >> sNumber;
    printf("----- �� ��ȣ�� ���� ���� -----\n");
    for (int i = 0; i < m_pSMS.size(); i++) {

        if (m_pSMS[i].getSender() == sNumber) {
            cout << "������� ��ȣ: " << m_pSMS[i].getReceiver() << endl;
            for (int k = 0; k < m_pPerson.size(); k++) {
                if (m_pPerson[k].getNumber() == m_pSMS[i].getReceiver()) {
                    cout << "# ������� �̸� : " << m_pPerson[i].getName() <<
                        " ���� : " << m_pPerson[i].getRelation() << endl;
                }
            }
            cout << "���� : " << m_pSMS[i].getContent() << endl;
        }
    }
}

void CAddressBook::WatchSMSReceiver()
{
    printf("�˻��� �ڵ��� ��ȣ�� �Է����ּ��� : ");
    string sNumber;
    std::cin >> sNumber;
    printf("----- �� ��ȣ�� ���� ���� -----\n");
    for (int i = 0; i < m_pSMS.size(); i++) {
        if (m_pSMS[i].getReceiver() == sNumber) {

            cout << "������� ��ȣ: " << m_pSMS[i].getSender() << endl;
            for (int k = 0; k < m_pPerson.size(); k++) {
                if (m_pPerson[k].getNumber() == m_pSMS[i].getSender()) {
                    cout << "# ������� �̸� : " << m_pPerson[k].getName() <<
                        " ���� : " << m_pPerson[k].getRelation() << endl;
                }
            }
            cout << "���� : " << m_pSMS[i].getContent() << endl;
        }
    }
}

// ���� ���� ó��
void CAddressBook::MakeDir()
{
    char strFolderPath[] = { "Data" };
    int nResult = _mkdir(strFolderPath);
    char strFolderPath2[] = { "Data\\SMS" };
    nResult = _mkdir(strFolderPath2);
}

void CAddressBook::LoadPerson()
{
    /* ��� ���� �ҷ����� */
    ifstream fin_entry("Data/Entry.txt");
    char receive[100];

    if (fin_entry.is_open()) {
        string sName;
        string sNumber;
        string sRelation = "";
        string sEmail = "";
        // ���� ���� �� ���� �ҷ�����
        while (fin_entry.getline(receive, sizeof(receive)))
        {
            sRelation = "";
            sEmail = "";

            int count = 0;
            char *context = NULL;
            char *ptr = strtok_s(receive, "&*(", &context);      // " " ���� ���ڸ� �������� ���ڿ��� �ڸ�, ������ ��ȯ

            while (ptr != NULL)               // �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
            {
                if (count == 0) sName = ptr;
                if (count == 1) sNumber = ptr;
                if (count == 2) sRelation = ptr;
                if (count == 3) sEmail = ptr;

                count++;
                ptr = strtok_s(NULL, "&*(", &context);      // ���� ���ڿ��� �߶� �����͸� ��ȯ
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
        // ���� ���� �� ���ο� ���� ����
        ofstream outputFile("Data/Entry.txt");
    }
}
void CAddressBook::LoadRelation()
{
    /* ���� ���� �ҷ����� */
    ifstream fin_relation("Data/Relation.txt");
    char receive[100];

    if (fin_relation.is_open()) {
        // ���� ���� �� ���� �ҷ�����
        while (fin_relation.getline(receive, sizeof(receive)))
        {
            m_sRelation.push_back(receive);
        }
    }
    else {
        // ���� ���� �� ���ο� ���� ����
        ofstream outputFile("Data/Relation.txt");
    }
}

void CAddressBook::LoadSMS()
{
    for (int i = 1; i < 21; i++) {
        /* SMS �ҷ����� */
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
    cout << "      ����ó" << endl;
    printf("n �̸�  ��ȣ        ����   �̸���\n");
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
    cout << " ���� ���" << endl;
    for (int i = 0; i < m_sRelation.size(); i++) {
        cout << i << ". " << m_sRelation[i] << endl;
    }
}
void CAddressBook::ShowSMS()
{
    cout << " SMS ���" << endl;
    for (int i = 0; i < m_pSMS.size(); i++) {
        cout << i << ". "
            << "������� : " << m_pSMS[i].getSender()
            << " ������� : " << m_pSMS[i].getReceiver() << endl;
    }
}
