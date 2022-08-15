//
// Created by kbg on 2022-06-28.
//

#ifndef STUDY_MYSTRING_H
#define STUDY_MYSTRING_H

#pragma once
#include <cstring>
#include <cstdio>

class CMyString{
public:
    //디폴트 생성자
    CMyString();

    // 변환 생성자
    CMyString(const char* _param);

    //복사 생성자
    CMyString(const CMyString &rhs);

    //이동 생성자
    CMyString(CMyString &&rhs);

    //대입 연산자
    CMyString& operator=(const CMyString &rhs);

    //덧셈 연산자
    CMyString operator+( const CMyString &rhs);
    CMyString& operator+=( const CMyString &rhs);

    //베열 연산자
    char& operator[](int nIndex);

    // 상수형 배열 연산자
    char operator[](int nIndex) const;

    //소멸자
    ~CMyString();

    operator char*(void) const;

    // 잘못된 데이터 삭제(delete) 명시
    int SetString(char* pszParam) = delete;
    int SetString( const char* pszParam) ;
    const char* GetString(void) const;
    int GetLength() const ;
    void Release(void) ;

    int Append( const char* pszParam) ;

private:
    int  m_nLength; //문자열 길이
    // 문자열 저장하기 위한 동적 할당한 메모리 포인터
     char* m_pszData;

};

#endif //STUDY_MYSTRING_H
