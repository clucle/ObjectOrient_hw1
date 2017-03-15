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
	NewPerson.setRelation(sRelation);
	NewPerson.setEmail(sEmail);
	m_pPerson.push_back(NewPerson);
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

void CAddressBook::CallMenu()
{
}


void CAddressBook::ShowPerson()
{
	vector<CPerson>::iterator it = m_pPerson.begin();
	for (; it < m_pPerson.end(); it++) {
		cout << it->getName()<< ' ' << it->getNumber()<<' ' << it->getRelation()<<' '<< it->getEmail()<<endl;
	}
}