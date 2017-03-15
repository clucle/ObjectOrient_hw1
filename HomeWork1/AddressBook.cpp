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
    // 이름으로 삭제
	for (int i = 0; i < m_pPerson.size(); i++) {
		if (m_pPerson[i].getName() == sName) {
			m_pPerson.erase(m_pPerson.begin() + i);
			break;
		}
	}
}
void CAddressBook::DelPerson_Pnumber(string sNumber)
{
    // 번호로 삭제
	for (int i = 0; i < m_pPerson.size(); i++) {
		if (m_pPerson[i].getNumber() == sNumber) {
			m_pPerson.erase(m_pPerson.begin() + i);
			break;
		}
	}
}
void CAddressBook::DelPerson_Order(int iOrder)
{
    // 순서로 삭제
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