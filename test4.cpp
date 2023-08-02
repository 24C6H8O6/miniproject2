#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string str1 = "ㅁ";
    string str2 = " ";
    // 2차원 벡터 선언
    vector<vector<string>> seat(14, vector<string>(5, "0"));

    // 2차원 벡터 초기화
    seat.resize(14); // 행 크기 지정
    for (int i = 0; i < 14; i++)
    {
        seat[i].resize(5); // 열 크기 지정
        for (int j = 0; j < 5; j++)
        {
            if (j == 2)
            {
                seat[i][j] = " ";
            }
            else
            {
                seat[i][j] = "ㅁ";
            }
        }
    }

    // 2차원 벡터 출력
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << seat[i][j];
        }
        cout << endl;
    }

    return 0;
}
