#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <ctime>
#include <vector>
#include <random>
#include "login1.h"
using namespace std;

int main()
{
    Ticketing aa;
    LOgin mylogin;
    int num = 0;
    int num2 = 0;
    // 유일한 번호 변수
    int unique;
    // 로그인 시 필요한 값
    int ret;
    // 로그인 구조체
    Login login;
    // 로그인할 때 파일 출력하는 구조체
    Login print;
    // 회원가입 구조체
    Login account;
    // 회원가입 화면
    cout << "           << 주 의 사 항>>" << endl;
    cout << "아이디, 이메일, 폰 번호 중 하나라도 중복되면" << endl;
    cout << "처음부터 다시 입력해야하니 신중을 기하십시오" << endl;

    // 회원가입
    mylogin.account2(account, print);

    // system("clear");

    // 아이디 찾기
    mylogin.findid(account, print);
    mylogin.findpw(account, print);
    // 로그인
    // C++에서 파일에서 값들을 불러오어 컴마(,)로 구분한 후 구조체에 저장하려면
    // std::ifstream 클래스와 std::getline 함수를 사용할 수 있다.
    mylogin.login2(login, print);
    // cout << account.id << endl;
    aa.getloginid(mylogin);
    aa.input();
    int b = aa.get_curr_hour();
    cout << b << endl;
    system("cls");
    aa.seats();
    aa.payment();
    aa.tickets();
    return 0;
}