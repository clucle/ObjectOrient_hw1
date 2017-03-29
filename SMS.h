#pragma once
#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif

class CSMS
{
private:
    std::string m_sType;
    std::string m_sNumber;
    std::string m_sContent;

public:
    CSMS(std::string sType, std::string sNumber, std::string sContent);
    ~CSMS();

    std::string getType() { return m_sType; };
    std::string getNumber() { return m_sNumber; };
    std::string getContent() { return m_sContent; };
};

