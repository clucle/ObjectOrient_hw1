#include "Person.h"

CPerson::CPerson(string sName, string sNumber)
{
	m_sName = sName;
	m_sNumber = sNumber;
    m_sRelation = "";
    m_sEmail = "";
}

CPerson::~CPerson()
{
}
