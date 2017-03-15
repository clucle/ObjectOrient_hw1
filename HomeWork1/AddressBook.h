#pragma once
#include "Person.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <vector>
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
    void DelPerson(string sName = NULL, string sPhone = NULL);

    void AddRelation(string sName);
    void DelRelation(string sName);

    void Load();
    void LoadPerson();
    void LoadRelation();

    void Save();
    void SavePerson();
    void SaveRelation();

    void Search();
    void CallMenu();
};

