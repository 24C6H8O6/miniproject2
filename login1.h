// login1.h(헤더파일)
#ifndef LOGIN1_H_
#define LOGIN1_H_
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
    // friend class Ticketing;
    string ID;
    string PW;
    string Email;
    string phone;
    Login p;
    int flag4 = 0;

public:
    int login2(Login login, Login print);     // 로그인
    int account2(Login account, Login print); // 회원가입
    void unique(Login &account);              // 회원번호 생성 및 저장
    int findid(Login account, Login print);   // 아이디 찾기
    int findpw(Login account, Login print);   // 비밀번호 찾기
    // string receiveid();
    void print_account2();
    void print_bokrail();
    void choice_login();
    void totallogin(Login login, Login print, Login account);
};

// 예매 클래스
class Ticketing
{
private:
    // friend class LOgin;          // 로그인과 프렌드
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
    vector<vector<string>> seat; // 2차원 벡터(좌석)석
    int row;                     // 행
    string column;               // 열
    int column2 = 0;             // 열을 새로운 변수로 지정
    int flag3;                   // while루프 관련 변수
    int ticket1;                 // 승차권 확인 변수
    vector<int> depart1 = {1, 2, 3, 4, 5, 6};
    vector<string> depart2 = {"서울", "대전", "광주", "대구", "울산", "부산"};

public:
    // 사용자가 출발지, 도착지, 날짜 => 시간표
    void input();
    void choice();
    void times();
    // 좌석 선택
    int get_curr_hour() const;
    void seats();
    int choice_seat();
    // 결재
    void payment();
    // 승차권
    void tickets();
    void arrive_depart();
    void normal_spec();
    int ticket_confirm();
    void reset_seat();
};

#endif
// login2.cpp(함수만 있는 cpp)