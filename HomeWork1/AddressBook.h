#pragma once
#include "Person.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
class CAddressBook
{
private:
    unsigned __int16 m_nCount;
    vector<CPerson> m_pPerson;

public:
    CAddressBook();
    ~CAddressBook();

    void AddPerson(string sName, string sNumber, string sRelation, string sEmail);
	void AddPerson(string sName, string sNumber);
	void AddPerson(string sName, string sNumber, string sRelation);
	void AddPerson(string sName, string sNumber, string sEmail);
    void DelPerson(string sName, string sPhone);

    void AddRelation(string sName);
    void DelRelation(string sName);

    void Load();
    void Save();

    void Search();
    void CallMenu();
};

