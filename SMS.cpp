#include "SMS.h"


CSMS::CSMS(std::string sSender, std::string sReceiver, std::string sContent)
{
    m_sSender = sSender;
    m_sReceiver = sReceiver;
    m_sContent = sContent;
}

CSMS::~CSMS()
{
}
