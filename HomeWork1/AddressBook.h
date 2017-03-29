#pragma once
#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif
#include <string.h>
#include "Person.h"
#include "Search.h"
#include "SMS.h"
#include <sys/stat.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
class CAddressBook
{
private:
    vector<CPerson> m_pPerson;

    vector<string> m_sRelation;
    unsigned int m_nRelation;

    vector<CSMS> m_pSMS;

public:
    CAddressBook();
    ~CAddressBook();

    void Init();

public:
    // 유저 접근 (기능 단위 Do)
    void DoAddPerson();
    void DoDelPerson();
    void DoAddRelation();
    void DoDelRelation();
    void DoSearchPerson();
    void DoModifyPerson();
    void DoWatchSMS();
    void DoShowPerson();

private:
    // 주요 기능 처리
    void AddPerson(string sName, string sNumber, string sRelation, string sEmail);

    void DelPersonName(string sName);
    void DelPersonNumber(string sNumber);
    void DelPersonOrder(int iOrder);

    void AddRelation(string sName);
    void DelRelation(string sName);

    void SearchPersonName(string sName);
    void SearchPersonNumber(string sNumber);
    void SearchPersonRelation(int iRelation);

    void ModifyPersonName(int iNum);
    void ModifyPersonNumber(int iNum);
    void ModifyPersonRelation(int iNum);
    void ModifyPersonEmail(int iNum);

    void WatchSMSOrder();
    void WatchSMSSender();
    void WatchSMSReceiver();


private:
    // 내부 로직
    void MakeDir();
    void LoadPerson();
    void LoadRelation();
    void LoadSMS();

    void SavePerson();
    void SaveRelation();

    void SortPerson();

    void ClearScreen() { cout << string(100, '\n'); }

    bool SelectCorrect(int num, int max);

    void ShowPerson();
    void ShowRelation();
    void ShowSMS();

};

