#pragma once

#ifndef __STRING_H__
#define __STRING_H__
#include <string>
#endif

#include <vector>
class CSearch
{
public:
    CSearch();
    ~CSearch();

    bool isSearched(std::string sName, std::string sFind);
};

