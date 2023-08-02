#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main() {

    std::string str = "Hello,World,C++";
    char separator = ',';
    std::istringstream iss(str);
    std::string str_buf;
    while (getline(iss, str_buf, separator)) {
    	  std::cout << str_buf << std::endl;
    }

    string line;
	while (getline(fin, line))
    {
        istringstream iss(line);
        getline(iss, account.id, ',');
        getline(iss, account.pw, ',');
        getline(iss, account.email, ',');
        getline(iss, account.phone);
        cout << account.id << endl 
        << account.pw << endl << account.email << endl << account.phone << endl;
        }

    fin.close();
    return 0;
}