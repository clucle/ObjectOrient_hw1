#pragma once
#include <string>

using namespace std;

class CPerson
{
private:
    string m_sName;
    string m_sNumber;
    string m_sRelation;

public:
    CPerson(string sName, string sNumber, string m_sRelation);
    ~CPerson();

    string getName() { return m_sName; }
    string getNumber() { return m_sNumber; }
    string getRelation() { return m_sRelation; }

    string setName(string sName) 
        { m_sName = sName; }
    string setNumber(string sNumber)
        { m_sNumber = sNumber; }
    string setRelation(string sRelation)
        { m_sRelation = sRelation; }
};

