//
// Created by kbg on 2022-06-28.
//
#include "stdafx.h"
#include "MyString.h"
#include "MyStringEx.h"

// 디폴트 생성자
CMyString::CMyString() :m_pszData(nullptr), m_nLength(0){
}

// 변환 생성자
CMyString::CMyString(const char* _param) {
    m_nLength = strlen(_param);
    m_pszData = new char[m_nLength];
    snprintf(m_pszData, m_nLength+1, "%s", _param);
}

// 복사 생성자
CMyString::CMyString( const CMyString &rhs) : m_pszData(NULL), m_nLength(0){
    this->SetString(rhs.GetString());
}

//이동 생성자
CMyString::CMyString(CMyString &&rhs) :m_pszData(NULL), m_nLength(0){
    cout << "CMyString &&" <<endl;

    // 얕은 복사를 수행해도 상관없다 어차피 원본이 곧 소멸되기 때문
    m_pszData = rhs.m_pszData;
    m_nLength = rhs.m_nLength;

    //원본 임시 객체 멤버들은 초기화한다. 절대로 해제하면 안된다.
    rhs.m_pszData = nullptr;
    rhs.m_nLength = 0;
}
// 대입 연산자
CMyString& CMyString::operator=(const CMyString &rhs) {

    if (this == &rhs)
        return *this;

    m_nLength = rhs.m_nLength;

    delete m_pszData;
    m_pszData = new char[m_nLength];
    memcpy(m_pszData, rhs.m_pszData, m_nLength);

    return *this;
}

// 베열 연산자

CMyString CMyString::operator+( const CMyString &rhs) {
    CMyString tempString(m_pszData);
    tempString.Append(rhs.m_pszData);
    return tempString;
}

CMyString& CMyString::operator+=(const CMyString &rhs) {
    Append(rhs.m_pszData);
    return *this;
}

char& CMyString::operator[](int nIndex){
    return m_pszData[nIndex];
}

char CMyString::operator[](int nIndex) const {
    return m_pszData[nIndex];
}
// 형 변환 연산자
CMyString::operator char*(void) const {
    cout << "operator char*" << endl;
    return m_pszData;
}

CMyString::~CMyString() {
    Release();
}

int CMyString::SetString(const char *pszParam)  {

    Release();

    if ( pszParam == nullptr)
        return 0;

    int nLength = strlen(pszParam);
    if ( nLength == 0)
        return 0;

    m_pszData = new char[nLength +1];

    memcpy(m_pszData, pszParam, nLength);
    m_nLength = nLength;

    OnSetString(m_pszData, nLength);

    return nLength;
}

// 상수형 메소드, 읽을수는 있지만 쓸수는 없다
const char *CMyString::GetString() const {
    return this->m_pszData;
}

int CMyString::GetLength() const {
    return m_nLength;
}

int CMyString::Append( const char *pszParam)  {
    if ( pszParam == NULL )
        return 0;

    int nLenParam = strlen(pszParam);

    if ( m_pszData == NULL ){
        SetString(pszParam);

        return m_nLength;
    }

    int nLenCur = m_nLength;

    char *pszResult = new char[nLenCur + nLenParam + 1];

    strncpy(pszResult,  m_pszData, sizeof(char) * (nLenCur +1));
    strncpy(pszResult + ( sizeof(char) * nLenCur ), pszParam, sizeof(char) * (nLenParam +1));

    Release();

    m_pszData = pszResult;
    m_nLength = nLenCur + nLenParam;

    return m_nLength;
}

void CMyString::Release()  {
    if (this->m_pszData != nullptr )
    {
        delete [] m_pszData;
        this->m_pszData = nullptr; //delete는 NULL로 초기화하지 않는다.
        this->m_nLength = 0;
    }
}

int CMyString::operator==(const CMyString &rhs) {
    if ( m_pszData != NULL && rhs.m_pszData != NULL ) {
        if ( strcmp(m_pszData, rhs.m_pszData) == 0 ) {
            return 1;
        }
    }

    return 0;
}

int CMyString::operator!=(const CMyString &rhs) {
    if ( m_pszData != NULL && rhs.m_pszData ) {
        if ( !strcmp(m_pszData, rhs.m_pszData ) ) {
            return 1;
        }
    }
    return 0;
}

void CMyString::OnSetString(char *pszData, int nLength) {
}

CMyString operator+(const char *pszParam, const CMyString &strParam) {
    CMyString strResult(pszParam);
    strResult.Append(strParam.m_pszData);
    return strResult;
}


void TestFunc(const CMyString &strParam){
    string temp = strParam.GetString();
    temp[0] = 'A'; //    temp.operator[](0) = 'A';
    cout << strParam << endl;
    cout << strParam[0] << endl; // operator[]() const 호출
    cout << strParam[strParam.GetLength() -1] << endl; // operator[]() const 호출
}

CMyString TestFunc2(void){
    CMyString strTest("TestFunc() return");
    cout << strTest << endl;

    return strTest;
}


int main(int argc, char** argv)
{
    CMyString strData;
    CMyString strTest;
    strData.SetString("Hello");
    strData.SetString("hello");
    cout << strData.GetString() << endl;
    CMyString strNewData(strData);
    cout << strNewData.GetString() << endl;

    strNewData = strTest; // strNewData.operator=(strTest);
    cout << strNewData.GetString() << endl;

    CMyString strData2("Hello");

    TestFunc(strData2);
    ::TestFunc(CMyString("Heelo2"));

    TestFunc2();

    CMyString strLeft("Hello"), strRight("World"), strResult;
    strResult = strLeft + strRight;
    cout << strResult << endl;

    strLeft += CMyString("World");
    cout << strLeft << endl;

    CMyString strParam("HelloWorld");
    cout << strParam << endl;
    TestFunc(strParam);

    CMyStringEx strTest2;
    strTest2.SetString("멍멍이아들");
    cout << strTest2 << endl;

    CMyString First("World"), c;
    c = "Hello" + First; // c.operator+("Hello" + CMyString);
    cout << c << endl;

}
