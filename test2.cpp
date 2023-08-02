#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;
// 회원정보 관련 클래스 필요
// struct Login
// {
//     string id;
//     string pw;
//     string email;
//     string phone;
//     int unique;
// };

// class LOgin
// {
// private:
//     string id;
//     string pw;
//     string Email;
//     string phone;

// public:
//     int login2(Login login, Login print);
//     int account2(Login account, Login print);
//     void unique(Login &account);
//     int findid(Login account, Login print);
//     int findpw(Login account, Login print);
//     int test();
// };
// int LOgin::test(const LOgin &pt)
// {
//     input();
// }
// 예매
class Ticketing
{
private:
    int ticket;    // 1.편도, 2.왕복
    string depart; // 출발지
    string arrive; // 도착지
    // 출발시간
    // int curr_day;
    int curr_hour;
    int new_curr_hour;
    int curr_minute;
    int normal_charge;
    int special_charge;
    vector<vector<string>> seat;
    int row;
    string column;
    int column2 = 0;
    int flag3;
    //

public:
    // 사용자가 출발지, 도착지, 날짜 => 시간표
    void input();
    void choice();
    void times();
    int get_curr_hour() const;
    // 좌석 선택
    void seats();
    int choice_seat();
    // 결재
};

int Ticketing::choice_seat()
{
    int flag = 0;
    int flag2 = 0;
    char munja;
    while (!flag)
    {
        cout << "열을 입력해주세요(A,B,C,D) >> ";
        cin >> column;
        //
        cout << "행을 입력해주세요(1~14) >>";
        cin >> row;
        // 자리 변환
        if (column == "A")
        {
            column2 = 1;
        }
        else if (column == "B")
        {
            column2 = 2;
        }
        else if (column == "C")
        {
            column2 = 4;
        }
        else if (column == "D")
        {
            column2 = 5;
        }
        // 자리가 빈자리가 아니면 선택할 수 없음을 알리기(나중에 할 것)
        if (seat[row - 1][column2] == "■")
        {
            cout << "이미 예약된 자리입니다, 다시 입력해주세요" << endl;
            continue;
        }
        while (!flag2)
        {
            cout << "선택하신 자리가 " << row << column << "이 맞습니까?(y,n)";
            cin >> munja;
            if (munja == 'y')
            {
                cout << "자리 선택이 완료되었습니다" << endl;
                flag = 1;
                flag2 = 1;
            }
            else if (munja == 'n')
            {
                cout << "다시 선택해 주시기 바랍니다" << endl;
                break;
            }
            else
            {
                cout << "잘못된 선택입니다" << endl;
                cout << "다시 입력해주세요" << endl;
            }
        }
    }

    flag3 = 1;
    return flag3;
}

void Ticketing::seats()
{

    int num1;
    int num2;
    // vector<vector<string>> seat(14, vector<string>(6, "0"));
    seat = vector<vector<string>>(14, vector<string>(6, "0"));
    // 2차원 벡터 초기화

    seat.resize(14); // 행 크기 지정
    for (int i = 0; i < 14; i++)
    {
        seat[i].resize(6); // 열 크기 지정
        for (int j = 1; j < 6; j++)
        {
            if (j == 3)
            {
                seat[i][j] = " ";
            }
            else
            {
                seat[i][j] = "□";
            }
        }
        // seat[5][2] = "■";
    }
    for (int i = 0; i < 4; i++)
    {
        while (1)
        {
            num1 = (rand() % 13) + 1;
            num2 = (rand() % 5) + 1;
            if (num2 == 3)
                continue;
            else
                break;
        }
        seat[num1][num2] = "■";
    }
    flag3 = 0;
    // 2차원 벡터 출력
    do
    {
        cout << "No. A B   C D" << endl;
        int num = 1;
        for (int i = 0; i < 14; i++)
        {
            cout << num << " ";
            if (num < 10)
            {
                cout << " ";
            }
            for (int j = 1; j < 6; j++)
            {
                cout << seat[i][j] << " ";
            }
            cout << endl;
            num++;
        }
        if (flag3 == 0)
        {
            flag3 = choice_seat();
            seat[row - 1][column2] = "■";
        }
        cout << "행 : " << row << ", 열 : " << column << endl;
        flag3 += 1;
    } while (flag3 != 3);
    cout << depart << " " << arrive << " 출발시간 " << curr_hour << "시 "
         << row << "행" << column << "열" << endl;
    cout << "야호!!!" << endl;
}

void Ticketing::times()
{
    // 현재시간
    struct tm curr_tm;
    time_t curr_time = time(nullptr);

    localtime_r(&curr_time, &curr_tm);

    // int curr_year = curr_tm.tm_year + 1900;
    // int curr_month = curr_tm.tm_mon + 1;
    // curr_day = curr_tm.tm_mday;
    curr_hour = curr_tm.tm_hour;
    curr_minute = curr_tm.tm_min;
    // int curr_second = curr_tm.tm_sec;
    cout << "현재시간 " << curr_hour << ":" << curr_minute << endl;
    new_curr_hour = curr_hour + 1;
    cout << new_curr_hour << endl;
}

void Ticketing::input()
{
    int num;
    times();
    // 편도 또는 왕복 출력문 넣을 것
    cout << "편도인지 왕복인지 고르시오 >> ";
    cin >> ticket;
    // 출발지, 도착지 출력문 넣을 것
    // 서울,대구,대전,광주,울산,부산
    // 출발지 배열(벡터) 랜덤
    // 도착지도 마찬가지
    cout << "출발지 선택 >> ";
    cin >> depart;
    cout << "도착지 선택 >> ";
    cin >> arrive;
    // cout << "출발시간 입력";
    // cin >> arrive;
    if ((depart == "광주") && (arrive == "서울"))
    {
        normal_charge = 46800;
        special_charge = 65500;
        cout << "번호    출발지  도착지  출발시간  도착예정시간  일반실  특실" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i << "\t" << depart << "\t" << arrive << "\t" << (new_curr_hour + 2 * i) % 24
                 << "시\t" << (new_curr_hour + 2 + 2 * i) % 24 << "시\t" << normal_charge
                 << "원\t" << special_charge << "원" << endl;
        }
    }
    else if ((depart == "광주") && (arrive == "대전"))
    {
        cout << "번호 출발지  도착지  출발시간  도착예정시간" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i << "     " << depart << "    " << arrive << "     " << (new_curr_hour + 2 * i) % 24
                 << "시      " << (new_curr_hour + 2 + 2 * i) % 24 << "시 " << endl;
        }
    }
    cout << "번호를 선택하세요" << endl;
    cin >> num;
    curr_hour = (curr_hour + (2 * num) + 1) % 24;
}

int Ticketing::get_curr_hour() const
{
    return curr_hour;
}

int main()
{
    Ticketing aa;

    aa.input();
    int b = aa.get_curr_hour();
    cout << b << endl;
    system("clear");
    aa.seats();
    return 0;
}