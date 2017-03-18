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
    // �̸����� ����
	for (int i = 0; i < m_pPerson.size(); i++) {
		if (m_pPerson[i].getName() == sName) {
			m_pPerson.erase(m_pPerson.begin() + i);
			break;
		}
	}
}
void CAddressBook::DelPerson_Pnumber(string sNumber)
{
    // ��ȣ�� ����
	for (int i = 0; i < m_pPerson.size(); i++) {
		if (m_pPerson[i].getNumber() == sNumber) {
			m_pPerson.erase(m_pPerson.begin() + i);
			break;
		}
	}
}
void CAddressBook::DelPerson_Order(int iOrder)
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
            // ����ȭ��
            if (ichoice == 0) break; // ����
            if (ichoice == 1) state = 1; // ��� �߰�
            if (ichoice == 2) state = 2; // ��� ����
            if (ichoice == 3) state = 3; // ���� ��� �߰�
            if (ichoice == 4) state = 4; // ���� ��� ����
            if (ichoice == 5) state = 5; // ��� �˻�
            if (ichoice == 6) state = 6;
        }
        else if (state == 1) {
            // ��� �߰� ȭ��
            if (ichoice == 1) state = 0; //���� ȭ������ ���ư�
        }
        else if (state == 2) {
            // ��� ���� ȭ��
            if (ichoice == 0){
                state = 0;
            }
            if (ichoice == 1) state = 0; //���� ȭ������ ���ư�
        }
        else if (state == 3) {
            // ���� �߰� ȭ��
            if (ichoice == 1) state = 0;
        }
        else if (state == 4) {
            // ���� ���� ȭ��
            if (ichoice == 1) state = 0;
        }
        else if (state == 5) {
            // ��� �˻� ȭ��
            if (ichoice == 1) state = 0;
        }
        else if (state == 6) {
            // ��� �˻� ȭ��
            if (ichoice == 1) state = 0;
        }
	}
}

int CAddressBook::CallMenu(int state)
{
	int result = 0;
    if (state == 0) {

        printf("\n- ����� ���� -\n");
        printf("   0 : ������\n");
        printf("   1 : ��� �߰�\n");
        printf("   2 : ��� ����\n");
        printf("   3 : ���� ��� �߰�\n");
        printf("   4 : ���� ��� ����\n");
        printf("   5 : ��� �˻�\n");
        printf("   6 : ���� ����\n");


        printf(" �������ּ��� : ");

        cin >> result;
        if (SelectCorrect(result, 6)) return result;
    }
    else if (state == 1) {
        int num;
        string name = "", number = "", relation = "", Email = "";
        printf("\n");
        printf("�̸��� �Է����ּ��� : ");
        cin >> name;
        printf("��ȣ�� �Է����ּ��� : ");
        cin >> number;
        ShowRelation();
        printf("�����ȣ�� �Է����ּ���(����) ������ x�Է� : ");
        if (m_sRelation.size() > 0) cin >> num;
        if (num < m_sRelation.size()) relation = m_sRelation[num];
        
        printf("Email �� �Է����ּ��� ������ x�Է� : ");
        cin >> Email;

        AddPerson(name, number, relation, Email);
        return 1;
    }
    else if (state == 2) {
        printf("\n�������� �����Ͻǰǰ���?\n");
        printf("0: �̸�, 1: ��ȭ��ȣ, 2: ����Ʈ�� ���� :");

        int pick = 0;
        cin >> pick;

        if (!SelectCorrect(result, 2)) return 1; // error

        ShowPerson();

        string sInput;
        int iInput;

        if (pick == 0) {
            printf("\n���� ����� �̸��� �Է����ּ��� : ");
            cin >> sInput;
            DelPerson_Name(sInput);
        }
        else if (pick == 1) {
            printf("\n���� ����� ��ȣ�� �Է����ּ��� : ");
            cin >> sInput;
            DelPerson_Pnumber(sInput);
        }
        else if (pick == 2) {
            printf("\n���� ����� ����Ʈ ��ȣ�� �Է����ּ��� : ");
            cin >> iInput;
            DelPerson_Order(iInput);
        }
        SavePerson();
        return 1;
    }
    else if (state == 3) {
        ShowRelation();
        string sInput;
        printf("\n�߰��� ���� ����� �����ּ��� : ");
        cin >> sInput;
        AddRelation(sInput);
        return 1;
    }
    else if (state == 4) {
        ShowRelation();
        string sInput;
        printf("\n������ ���� ����� �����ּ��� : ");
        cin >> sInput;
        DelRelation(sInput);
        return 1;
    }
    else if (state == 5) {
        printf("\n�������� �˻��Ͻǰǰ���?\n");
        printf("0: �̸�, 1: ��ȭ��ȣ, 2: ����  �� �˻� :");

        int pick = 0;
        cin >> pick;

        if (!SelectCorrect(result, 2)) return 1;


        if (pick < 2) {
            printf("�˻��� �ܾ��� �Ϻ� : ");
            string sFind;
            cin >> sFind;

            cout << "\n      ����ó" << endl;
            printf("n �̸�  ��ȣ        ����   �̸���\n");
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
            printf("���� ��ȣ�� �Է����ּ���: ");
            cin >> iRelation;

            cout << "\n      ����ó" << endl;
            printf("n �̸�  ��ȣ        ����   �̸���\n");
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
        
        printf("\n�ƹ��ų� �Է��ϸ� ���ư��ϴ�.\n");

        string noProgress;
        cin >> noProgress;
        
        return 1;
    }
    else if (state == 6) {
        ShowPerson();
        printf("\n������ ����� ��ȣ�� �������ּ��� : ");
        int iNum = 0;
        cin >> iNum;

        int iSelect;
        printf("������ �� �������ּ���\n");
        printf("  0: �̸� \n");
        printf("  1: ��ȣ \n");
        printf("  2: ���� \n");
        printf("  3: Email \n");
        printf(" ���� �� ��ȣ : ");
        cin >> iSelect;

        string sChange;
        int iChange;
        
        ClearScreen();

        if (iSelect == 0) {
            printf("�̸��� �����մϴ�\n");
            printf("���� �� : ");
            cout << m_pPerson[iNum].getName() << endl;
            printf("���� �� : ");
            cin >> sChange;
            m_pPerson[iNum].setName(sChange);
        }
        else if (iSelect == 1) {
            printf("��ȣ�� �����մϴ�\n");
            printf("���� �� : ");
            cout << m_pPerson[iNum].getNumber() << endl;
            printf("���� �� : ");
            cin >> sChange;
            m_pPerson[iNum].setNumber(sChange);
        }
        else if (iSelect == 2) {
            printf("���踦 �����մϴ�\n");
            printf("���� �� : ");
            cout << m_pPerson[iNum].getRelation() << endl;
            printf("���� �� : ");
            ShowRelation();
            printf("���� �� (����) // ������ x: ");
            cin >> iChange;

            if (iChange == 'x') m_pPerson[iNum].setRelation("");
            else m_pPerson[iNum].setRelation(m_sRelation[iChange]);
        }
        else if (iSelect == 3) {
            printf("Email�� �����մϴ�\n");
            printf("���� �� : ");
            cout << m_pPerson[iNum].getEmail() << endl;
            printf("���� �� : ");
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
	cout << "      ����ó" << endl;
	printf("n �̸�  ��ȣ        ����   �̸���\n");
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
	cout << " ���� ���" << endl;
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