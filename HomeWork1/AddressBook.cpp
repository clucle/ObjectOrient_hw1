#include "AddressBook.h"

CAddressBook::CAddressBook()
{
}


CAddressBook::~CAddressBook()
{
}

void CAddressBook::AddPerson(string sName, string sNumber, string sRelation, string sEmail)
{
	CPerson NewPerson(sName, sNumber, sRelation, sEmail) ;
	m_pPerson.push_back(NewPerson);
}

void CAddressBook::DelPerson(string sName, string sPhone)
{
}

void CAddressBook::AddRelation(string sName)
{
}

void CAddressBook::DelRelation(string sName)
{
}

void CAddressBook::Load()
{
    // �̸�, ��ȣ, ���� �ҷ�����
    ifstream fin("Data/Entry.txt");
    char receive[100];
	int i = 1;
    if (fin.is_open()) {
        // ���� ���� �� ���� �ҷ�����
        while (fin.getline(receive, sizeof(receive)))
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

void CAddressBook::Save()
{
    ofstream fout;
    fout.open("Data/Entry.txt");
    fout << "write line 1" << endl;
    fout << "write line 2";
    fout.close();
}

void CAddressBook::Search()
{
}

void CAddressBook::CallMenu()
{
}
