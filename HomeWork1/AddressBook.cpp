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
    vector<CPerson> vPerson;
    int nCount = 20;

    for (int i = 0; i < nCount; i++) {
        CPerson a("AC" + std::to_string(i), "B", "C", "D");
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

void CAddressBook::Search()
{
}

void CAddressBook::CallMenu()
{
}
