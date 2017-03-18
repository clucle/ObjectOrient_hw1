#pragma once
#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif
#include <string.h>
#include "Person.h"
#include "Search.h"
#include "SMS.h"


#include <fstream>
#include <iostream>
#include <algorithm>
#include <direct.h>

using namespace std;
class CAddressBook
{
private:
    vector<CPerson> m_pPerson;

    vector<string> m_sRelation;
    unsigned __int16 m_nRelation;

    vector<CSMS> m_pSMS;

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
    void LoadSMS();

    void SavePerson();
    void SaveRelation();

    void SortPerson();

    void Search();
    
	void Run();


	// View
	int CallMenu(int state);
	void ShowPerson();
	void ShowRelation();
    void ShowSMS();

    // mkdir
    void MakeDir();

    void ClearScreen()
    {
        cout << string(100, '\n');
    }
    bool SelectCorrect(int num, int max);

};

