#pragma once
#include <string>
class CSMS
{
private:
    std::string m_sSender;
    std::string m_sReceiver;
    std::string m_sContent;

public:
    CSMS(std::string sSender, std::string sReceiver, std::string sContent);
    ~CSMS();
};

