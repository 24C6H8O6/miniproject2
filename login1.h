#ifndef LOGIN1_H_
#define LOGIN1_H_

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <fstream>
// #include <random>
// #include <unistd.h>
// #include <cstdlib>
// #include <cstring>
// #include <sstream>
// #include <ctime>

#include <string>
#include <vector>

using namespace std;
// 구조체
struct Login
{
    string id;
    string pw;
    string email;
    string phone;
    int unique;
};

// 로그인 클래스
class LOgin
{
private:
    friend class Ticketing;
    string ID;
    string PW;
    string Email;
    string phone;
    Login p;

public:
    int login2(Login login, Login print);
    int account2(Login account, Login print);
    void unique(Login &account);
    int findid(Login account, Login print);
    int findpw(Login account, Login print);
    string receiveid();
    void print_account2();
    void print_bokrail();
    void choice_login();
    void totallogin(Login login, Login print, Login account);
};

// 예매 클래스
class Ticketing
{
private:
    friend class LOgin;          // 로그인과 프렌드
    string var;                  // 로그인 클래스와 연결하기 위한 값
    int ticket;                  // 1.편도, 2.왕복
    string depart;               // 출발지
    string arrive;               // 도착지
    int curr_year;               // 년
    int curr_month;              // 월
    int curr_day;                // 일
    int curr_hour;               // 출발 시간
    int new_curr_hour;           // 출발 시간을 새롭게 변수로 지정
    int curr_minute;             // 분
    int normal_charge;           // 일반실 요금
    int special_charge;          // 특실 요금
    string charge_num;           // 일반실 선택 번호
    int charge;                  // 요금
    vector<vector<string>> seat; // 2차원 벡터
    int row;                     // 행
    string column;               // 열
    int column2 = 0;             // 열을 새로운 변수로 지정
    int flag3;                   // while루프 관련 변수
    int ticket1;                 // 승차권 확인 변수

public:
    void getloginid(LOgin &t);
    // 사용자가 출발지, 도착지, 날짜 => 시간표
    void input();
    void choice();
    void times();
    int get_curr_hour() const;
    // 좌석 선택
    void seats();
    int choice_seat();
    // 결재
    void payment();
    // 승차권
    void tickets();
    void arrive_depart();
    void normal_spec();
    int ticket_confirm();
};

#endif