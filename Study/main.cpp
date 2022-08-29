//
// Created by daimo on 2022-08-29.
//

#include <iostream>
#include <vector>

using namespace std;

class CMyData{
public:
    CMyData(){
        cout << "CMyData" << endl;
    }
    virtual ~CMyData(){}
    // 순수 가상 함수 선언
    virtual int GetID() const = 0;

protected:
    int m_id;
};

// 파생 클래스 형식으로 받은 후 해당 파생 클래스의 가상함수 호춣
void PrintID(CMyData* pObj){
    cout << "ID : " << pObj->GetID() << endl;
}
class CMyDataEx1 : public CMyData {
public:
    explicit CMyDataEx1(int nId) {  m_id = nId;   }

    virtual int GetID()  const {
        cout << "CMyDataEx1 GetID() " << endl;
        return m_id;
    }
};

class CMyDataEx2 : public CMyData {
public:
    CMyDataEx2(int nId) {   m_id = nId;   }

    virtual int GetID()  const {
        cout << "CMyDataEx2 GetID() " << endl;
        return m_id;
    }
};

int main(int argc, char** argv) {
    CMyDataEx1 a(10);
    CMyDataEx2 b(20);
    PrintID(&a);
    PrintID(&b);

    // 형변환,
    CMyData* pA = static_cast<CMyDataEx1*>(&a);
    PrintID(pA);
    pA = static_cast<CMyDataEx2*>(&b);
    PrintID(pA);
}
