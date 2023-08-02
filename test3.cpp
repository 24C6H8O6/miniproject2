// 아직 stream을 배우지 않았기 때문에 C 언어용 출력 함수 사용!
#include <stdio.h>

class A
{
public:
    void ShowData() // A 클래스용 출력 함수
    {
        printf("A객체 입니다!\n");
    }
};

class B
{
private:
    A *mp_a_object; // A 클래스로 만들어진 객체의 주소를 저장할 포인터!

public:
    // B 클래스의 객체 생성자 - 멤버 변수를 초기화
    B()
    {
        mp_a_object = NULL;
    }
    // A 클래스로 만들어진 객체의 주소를 넘겨 받아서 멤버 변수에 저장!
    void Link(A *ap_a_object)
    {
        mp_a_object = ap_a_object;
        printf("A와 연결되었습니다!\n");
    }
    // B 클래스용 출력 함수
    void ShowData()
    {
        printf("B객체 입니다!\n");
    }
    // A 클래스용 출력 함수
    void ShowDataA()
    {
        mp_a_object->ShowData(); // A 클래스의 ShowData 함수를 호출한다.
    }
};

int main()
{
    A temp; // A 클래스로 객체를 생성한다.
    B data; // B 클래스로 객체를 생성한다.

    // B 객체에 A 객체의 주소를 전달한다.
    // B 클래스의 mp_a_object에 temp 객체의 주소가 저장된다!
    data.Link(&temp);
    // B 클래스용 출력 함수를 호출한다.
    data.ShowData();
    // A 클래스용 출력 함수를 호출한다. temp 객체의 ShowData 함수가 호출됨!
    data.ShowDataA();
    return 0;
}