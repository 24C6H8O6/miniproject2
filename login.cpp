// 파일 최종

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <sstream>

/*
class 회원가입
{
private:
    string ID;
    string PW;
    string Email;
    string phone;

public:
    아이디 중복 확인 함수
}
*/

using namespace std;
struct Login
{
    string id;
    string pw;
    string email;
    string phone;
};

int main()
{

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
    // 회원가입
    // cout << "ID를 입력하세요 >> ";
    // getline(cin, account.id);
    // // cin >> account.id;
    // cout << "PW를 입력하세요 >> ";
    // getline(cin, account.pw);
    // // cin >> account.pw;
    // cout << "E-Mail을 입력하세요 >> ";
    // getline(cin, account.email);
    // cout << "휴대폰 번호를 입력하세요 >> ";
    // getline(cin, account.phone);
    // 회원가입 화면
    cout << "              <<주의사항>>" << endl;
    cout << "아이디, 이메일, 폰 번호 중 하나라도 중복되면" << endl;
    cout << "처음부터 다시 입력해야하니 신중을 기하십시오" << endl;
    while (!num2)
    {
        int num3 = 0;
        int num4 = 0;
        // 유일한 번호 변수
        unique = 0;
        ifstream fin("/home/lms116/다운로드/miniproject2/member.txt", ios_base::in);
        if (!fin.is_open())
        {
            cerr << "안 열림" << endl;
            return 1;
        }
        cout << "ID를 입력하세요 >> ";
        getline(cin, account.id);
        // cin >> account.id;

        string line2;
        while (getline(fin, line2))
        {
            unique += 1;
            istringstream iss(line2);
            getline(iss, print.id, ',');
            getline(iss, print.pw, ',');
            getline(iss, print.email, ',');
            getline(iss, print.phone, ',');
            // cout << print.id << ' '
            //      << print.pw << ' ' << print.email << ' ' << print.phone << endl;
            if (account.id == print.id)
            {
                num3 += 1;
            }
            else
            {
                num4 = 0;
            }
        }
        if (num3 == 0)
        {
            cout << "사용가능한 아이디" << endl;
            num2 = 1;
        }
        else
        {
            cout << "아이디 중복, 다시 입력 요망!!" << endl;
            continue;
        }

        cout << "PW를 입력하세요 >> ";
        getline(cin, account.pw);
        // cin >> account.pw;

        cout << "E-Mail을 입력하세요 >> ";
        getline(cin, account.email);
        num3 = 0;

        string line3;
        while (getline(fin, line3))
        {
            num2 = 0;
            istringstream iss(line3);
            getline(iss, print.id, ',');
            getline(iss, print.pw, ',');
            getline(iss, print.email, ',');
            getline(iss, print.phone, ',');
            // cout << print.id << ' '
            //      << print.pw << ' ' << print.email << ' ' << print.phone << endl;
            if (account.email == print.email)
            {
                num3 += 1;
            }
            else
            {
                num4 = 0;
            }
        }
        if (num3 == 0)
        {
            cout << "사용가능한 이메일" << endl;
            num2 = 1;
        }
        else
        {
            cout << "이메일 중복, 다시 입력 요망!!" << endl;
            continue;
        }

        cout << "휴대폰 번호를 입력하세요 >> ";
        getline(cin, account.phone);
        num3 = 0;
        string line4;
        while (getline(fin, line4))
        {
            num2 = 0;
            istringstream iss(line4);
            getline(iss, print.id, ',');
            getline(iss, print.pw, ',');
            getline(iss, print.email, ',');
            getline(iss, print.phone, ',');
            // cout << print.id << ' '
            //      << print.pw << ' ' << print.email << ' ' << print.phone << endl;
            if (account.phone == print.phone)
            {
                num3 += 1;
            }
            else
            {
                num4 = 0;
            }
        }
        if (num3 == 0)
        {
            cout << "사용가능한 휴대폰 번호" << endl;
            num2 = 1;
        }
        else
        {
            cout << "휴대폰 번호 중복, 다시 입력 요망!!" << endl;
            continue;
        }

        fin.close();
    }
    // 회원번호 파일
    ofstream fout2("/home/lms116/다운로드/miniproject2/unique.txt", ios_base::app);
    fout2 << account.id << "," << unique << endl;
    fout2.close();

    ofstream fout("/home/lms116/다운로드/miniproject2/member.txt", ios_base::app);
    if (fout)
    {
        fout << account.id << "," << account.pw << "," << account.email << ","
             << account.phone << endl;
        cout << "아이디 : " << account.id << endl;
        cout << "이메일 : " << account.email << endl;
        cout << "휴대폰번호 : " << account.phone << endl;
        // 난수 부여 필요
        cout << "회원번호 : " << unique << endl;
    }
    else
    {
        // 버퍼 지움
        cerr << "입력 안 됨" << endl;
        return 1;
    }
    fout.close();
    // system("clear");

    // 아이디 찾기
    int num5 = 0;
    while (!num5)
    {
        num3 = 0;
        num4 = 0;
        ifstream fin("/home/lms116/다운로드/miniproject2/member.txt", ios_base::in);
        if (!fin.is_open())
        {
            cerr << "안 열림" << endl;
            return 1;
        }
        cout << "이메일을 입력하세요 >> ";
        getline(cin, account.email);
        while (getline(fin, line2))
        {
            unique += 1;
            istringstream iss(line2);
            getline(iss, print.id, ',');
            getline(iss, print.pw, ',');
            getline(iss, print.email, ',');
            getline(iss, print.phone, ',');
            if (account.email == print.email)
            {
                cout << "아이디는 " << print.id;
                num5 = 1;
                break;
            }
            else
            {
                num4 = 0;
            }
        }
    }

    // 로그인
    // C++에서 파일에서 값들을 불러오어 컴마(,)로 구분한 후 구조체에 저장하려면
    // std::ifstream 클래스와 std::getline 함수를 사용할 수 있다.

    while (!num)
    {
        ifstream fin("/home/lms116/다운로드/miniproject2/member.txt", ios_base::in);
        if (!fin.is_open())
        {
            cerr << "안 열림" << endl;
            return 1;
        }
        cout << "ID를 입력하세요 >> ";
        getline(cin, login.id);
        // cin >> account.id;
        cout << "PW를 입력하세요 >> ";
        getline(cin, login.pw);
        // cin >> account.pw;
        string line;
        while (getline(fin, line))
        {
            istringstream iss(line);
            getline(iss, print.id, ',');
            getline(iss, print.pw, ',');
            getline(iss, print.email, ',');
            getline(iss, print.phone, ',');
            cout << print.id << ' '
                 << print.pw << ' ' << print.email << ' ' << print.phone << endl;
            if ((login.id == print.id) && (login.pw == print.pw))
            {
                cout << "로그인 성공" << endl;
                num = 1;
                break;
            }
        }
        if (num == 0)
            cout << "로그인실패, 다시 입력 요망!!" << endl;
        fin.close();
    }
    cout << "!!!!!" << endl;

    return 0;
}