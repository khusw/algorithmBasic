/*
    문자열에 관한 기본적인 함수 및 각종 사용법을 정리한 파일

    문자열 분리, 문자열 합치기, 부분 문자열 발견하기 등 을 차차 기록해 나갈 파일임.
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// istringstream 을 활용한 문자열 구분
void IStringStream(string str)
{
    istringstream ss(str);
    string strBuffer;
    while (getline(ss, strBuffer, ' '))
    {
        // getline 에 delimiter 를 넣을 때 주의할 점은
        // "" 과 '' 는 다르다는 점이다.
        // "" 는 string 을 '' 는 char 를 의미한다
        // getline 의 delimiter 는 char 가 들어가야 한다.
        cout << strBuffer;
    }
}

int main()
{
    string str = "This is String";
    IStringStream(str);
    return 0;
}