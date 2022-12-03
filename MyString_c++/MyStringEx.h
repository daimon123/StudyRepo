//
// Created by kbg on 2022-08-16.
//

#ifndef STUDY_MYSTRINGEX_H
#define STUDY_MYSTRINGEX_H

#include "stdafx.h"
#include "MyString.h"

class CMyStringEx : public CMyString{
public:
    CMyStringEx();
    CMyStringEx(const char* pszparam);
    ~CMyStringEx();
    void OnSetString(char *pszData, int nLength); //부모 함수의 가상함수 정의
    int Find(const char* pszParam);
};


#endif //STUDY_MYSTRINGEX_H
