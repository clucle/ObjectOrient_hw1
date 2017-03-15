#pragma once
#include "Person.h"
#include <fstream>
#include <iostream>

class CAddressBook
{
private:
    unsigned __int16 m_nCount;
    CPerson* m_pPerson = NULL;

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
    void Save();

    void Search();
    void CallMenu();
};

