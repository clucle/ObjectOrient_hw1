#pragma once
#include "Person.h"
#include "Search.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <direct.h>

using namespace std;
class CAddressBook
{
private:
    unsigned __int16 m_nCount;
    vector<CPerson> m_pPerson;

    vector<string> m_sRelation;
    unsigned __int16 m_nRelation = 20;

public:
    CAddressBook();
    ~CAddressBook();

	void AddPerson(string sName, string sNumber, string sRelation, string sEmail);

    void DelPerson_Name(string sName);
	void DelPerson_Pnumber(string sNumber);
	void DelPerson_Order(int iOrder);

    void AddRelation(string sName);
    void DelRelation(string sName);

    void LoadPerson();
    void LoadRelation();

    void SavePerson();
    void SaveRelation();

    void SortPerson();

    void Search();
    
	void Run();


	// View
	int CallMenu(int state);
	void ShowPerson();
	void ShowRelation();

    // mkdir
    void MakeDir();

    void ClearScreen()
    {
        cout << string(100, '\n');
    }
    bool SelectCorrect(int num, int max);

};

