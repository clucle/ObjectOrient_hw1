#pragma once
#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif

class CSMS
{
private:
    std::string m_sSender;
    std::string m_sReceiver;
    std::string m_sContent;

public:
    CSMS(std::string sSender, std::string sReceiver, std::string sContent);
    ~CSMS();

    std::string getSender() { return m_sSender; };
    std::string getReceiver() { return m_sReceiver; };
    std::string getContent() { return m_sContent; };
};

