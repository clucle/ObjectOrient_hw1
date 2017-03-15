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
	//bool result = false;
	
	for (int i = 0; i < m_pPerson.size(); i++) {
		if (m_pPerson[i].getName() == sName) {
			//result = true;
			m_pPerson.erase(m_pPerson.begin() + i);
			break;
		}
	}
	/*
	cout << "AAA" << endl;
	string tmp;
	if (sName != "")
	{	
		vector<CPerson>::iterator it= m_pPerson.begin();
		


		for (; it < m_pPerson.end(); it++)
		{
			tmp = it->getName();
			if (tmp == sName && it != m_pPerson.end())
			{
				m_pPerson.erase(it);
			}
			else {
				printf("finding\n");
			}
		}
	}
	else
	{
		//error can't find
	}*/
	
}
void CAddressBook::DelPerson_Pnumber(string sNumber)
{
	for (int i = 0; i < m_pPerson.size(); i++) {
		if (m_pPerson[i].getNumber() == sNumber) {
			//result = true;
			m_pPerson.erase(m_pPerson.begin() + i);
			break;
		}
	}
}
void CAddressBook::DelPerson_Order(int iOrder)
{
	m_pPerson.erase(m_pPerson.begin() + iOrder);
	/*
	for (int i = 0; i < m_pPerson.size(); i++) {
		if (m_pPerson[i].getName() == sNumber) {
			//result = true;
			m_pPerson.erase(m_pPerson.begin() + i);
			break;
		}*/
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

	int i = 1;

    if (fin_entry.is_open()) {

        // ���� ���� �� ���� �ҷ�����
        while (fin_entry.getline(receive, sizeof(receive)))
        {
            cout << "Receive : "<< i <<" " << receive << endl;
			i++;
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
    vector<CPerson> vPerson;
    int nCount = 20;

    for (int i = 0; i < nCount; i++) {
        CPerson a("AC" + std::to_string(i), "B");
        vPerson.push_back(a);
    }
 
    ofstream fout;
    fout.open("Data/Entry.txt");

    for (int i = 0; i < nCount; i++) {
        fout << vPerson[i].getName()  << "&*(";
        fout << vPerson[i].getNumber() << "&*(";
        fout << vPerson[i].getRelation() << "&*(";
        fout << vPerson[i].getEmail() << endl;
    }
    
    fout.close();
}
void CAddressBook::SaveRelation()
{
    ofstream fout;
    fout.open("Data/Entry.txt");

    for (int i = 0; i < m_sRelation.size(); i++) {
        fout << m_sRelation[i] << endl;
    }

    fout.close();
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