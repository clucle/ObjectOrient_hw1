#include "AddressBook.h"

CAddressBook::CAddressBook()
{
}


CAddressBook::~CAddressBook()
{
}

void CAddressBook::AddPerson(string sName, string sNumber, string sRelation)
{
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
    ifstream in("Data/Entry.txt");
    char receive[100];

    if (in.is_open()) {
        // ���� ���� �� ���� �ҷ�����
        while (in.getline(receive, sizeof(receive)))
        {
            cout << "Receive : " << receive << endl;
        }        
    }
    else {
        // ���� ���� �� ���ο� ���� ����
        ofstream outputFile("Data/Entry.txt");
    }
}

void CAddressBook::Save()
{
}

void CAddressBook::Search()
{
}

void CAddressBook::CallMenu()
{
}
