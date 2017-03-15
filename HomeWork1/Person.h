#pragma once
#include <string>

using namespace std;

class CPerson
{
private:
    string m_sName;
    string m_sNumber;
    string m_sRelation;
    string m_sEmail;

public:
    CPerson(string sName, string sNumber,
         string m_sRelation, string m_sEmail);
    ~CPerson();

    string getName() { return m_sName; }
    string getNumber() { return m_sNumber; }
    string getRelation() { return m_sRelation; }
    string getEmail() { return m_sEmail; }

    string setName(string sName) 
        { m_sName = sName; }
    string setNumber(string sNumber)
        { m_sNumber = sNumber; }
    string setRelation(string sRelation)
        { m_sRelation = sRelation; }
    string setEmail(string sEmail)
        { m_sEmail = sEmail; }
};

