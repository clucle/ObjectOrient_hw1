#include "Person.h"

CPerson::CPerson(string sName, string sNumber, string sRelation, string sEmail)
{
    m_sName = sName;
    m_sNumber = sNumber;
    m_sRelation = sRelation;
    m_sEmail = sEmail;
}

CPerson::~CPerson()
{
}
