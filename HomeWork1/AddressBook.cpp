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
    // 이름, 번호, 관계 불러오기
    ifstream fin("Data/Entry.txt");
    char receive[100];

    if (fin.is_open()) {
        // 파일 있을 시 정보 불러오기
        while (fin.getline(receive, sizeof(receive)))
        {
            cout << "Receive : " << receive << endl;
        }        
    }
    else {
        // 파일 없을 시 새로운 파일 생성
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
