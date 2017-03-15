#pragma once
#include <string>

using namespace std;

class CPerson
{
private:
    string m_sName;
    string m_sNumber;
    string m_sRelation="";
    string m_sEmail="";

public:
	CPerson(string sName, string sNumber);
    ~CPerson();

    string getName() { return m_sName; }
    string getNumber() { return m_sNumber; }
    string getRelation() { return m_sRelation; }
    string getEmail() { return m_sEmail; }

    void setName(string sName) 
        { m_sName = sName; }
    void setNumber(string sNumber)
        { m_sNumber = sNumber; }
    void setRelation(string sRelation)
        { m_sRelation = sRelation; }
    void setEmail(string sEmail)
        { m_sEmail = sEmail; }
};

