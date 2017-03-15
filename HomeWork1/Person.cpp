#include "Person.h"

CPerson::CPerson(string sName, string sNumber, string sRelation, string sEmail)
{
    m_sName = sName;
    m_sNumber = sNumber;
    m_sRelation = sRelation;
    m_sEmail = sEmail;
}

CPerson::CPerson(string sName, string sNumber)
{
	m_sName = sName;
	m_sNumber = sNumber;
}
CPerson::CPerson(string sName, string sNumber,string sRelation)
{
	m_sName = sName;
	m_sNumber = sNumber;
	m_sRelation = sRelation;
}
CPerson::CPerson(string sName, string sNumber,string sEmail)
{
	m_sName = sName;
	m_sNumber = sNumber;
	m_sEmail = sEmail;
}

CPerson::~CPerson()
{
}
