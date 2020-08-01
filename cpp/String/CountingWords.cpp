/*
    BOJ 1152 단어의 갯수 
    https://www.acmicpc.net/problem/1152

    영어 대소문자와 띄어쓰기로 주어진 문자열이 입력으로 주어진다.
    이 문자열에 과연 몇개의 단어가 존재하는지 출력하는 프로그램을 작성하는 문제

    입력 문자열의 최대 길이는 백만 이하 이다.
    단어는 띄어쓰기 한개로 구분되며, 공백이 연속해서 나오지는 않는다.
    문자열 맨 앞,뒤에 공백이 존재할 수도 있다.

    출력은 단어의 갯수를 출력한다.
*/
#include <iostream>
#include <string>

using namespace std;

string inStr;
int spaceCount = 1;

void countWord(string str)
{
    int length = str.size();

    if (str[0] == ' ')
    {
        spaceCount = 0;
    }

    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')
        {
            spaceCount++;
        }
    }

    if (str[length - 1] == ' ')
    {
        spaceCount--;
    }

    cout << spaceCount;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    getline(cin, inStr);

    countWord(inStr);

    return 0;
}