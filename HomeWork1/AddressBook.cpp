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

void CAddressBook::LoadPerson()
{
    /* 사람 관련 불러오기 */
    ifstream fin_entry("Data/Entry.txt");
    char receive[100];

    if (fin_entry.is_open()) {
        // 파일 있을 시 정보 불러오기
        while (fin_entry.getline(receive, sizeof(receive)))
        {
            cout << "Receive : " << receive << endl;
        }        
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
    fout << "write line 1" << endl;
    fout << "write line 2";
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
