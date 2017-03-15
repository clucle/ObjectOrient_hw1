#pragma once
#include "Person.h"
#include <vector>
#include <fstream>
#include <iostream>

class CAddressBook
{
private:
    unsigned __int16 m_nCount;
    CPerson* m_pPerson = NULL;

    vector<string> m_sRelation;
    unsigned __int16 m_nRelation = 20;

public:
    CAddressBook();
    ~CAddressBook();

    void AddPerson(string sName, string sNumber,
        string sRelation);
    void DelPerson(string sName = NULL,
        string sPhone = NULL);

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

