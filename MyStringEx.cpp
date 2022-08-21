//
// Created by kbg on 2022-08-16.
//

#include "MyStringEx.h"
#include "MyString.h"


CMyStringEx::CMyStringEx() {

}

CMyStringEx::~CMyStringEx() {

}

// 부모 생성자 상속
CMyStringEx::CMyStringEx(const char* pszparam) : CMyString(pszparam) {

}

int CMyStringEx::Find(const char *pszParam) {
    if ( pszParam == NULL || GetString() == NULL )
        return -1;

    const char* pszResult = strstr(GetString(), pszParam);
    if ( pszResult ){
        return pszResult - GetString();
    }
    return -1;
}

void CMyStringEx::OnSetString(char *pszData, int nLength) {
    if ( !strcmp(pszData, "멍멍이아들") ){
        snprintf(pszData, sizeof(char) * (nLength +1), "착한아들");
    }

}