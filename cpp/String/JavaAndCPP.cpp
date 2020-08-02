/*
    BOJ 3613 Java VS C++
    https://www.acmicpc.net/problem/3613

    문자열 입력이 주어졌을 때,
    그 문자가 Java 형식의 언어이면, c++ 형식으로 바꾸고,
    c++ 형식의 언어이면, java 형식의 언어로 바꾸는 문제

    java 형식의 언어란 camel case 로 구성된 언어를 말하며,
    (javaImplementation, longAndMemory 등)

    c++ 형식의 언어란, _ 로 단어를 구분한 언어를 말한다.
    (c_identifier, name_two 등)
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;

    bool isCpp = false, isJava = false, isError = false;
    string result;

    for (int i = 0; i < str.length(); i++)
    {
        // java
        if (isupper(str[i]))
        { // 대문자 이면서
            if (!i || isCpp)
            { // 첫글자이거나 cpp 언어가 아닌 경우
                isError = true;
                break;
            }
            // 들어온 문자가 java 언어이므로 이를 cpp 로 바꾸기 위해서
            // '_' 를 추가해주고, str[i] - 'A' + 'a' 는 아스키 코드 연산에 의해서 소문자로 바꾸겠다는 의미다.
            result += '_';
            result += str[i] - 'A' + 'a';
            isJava = true; // 위 과정을 다 거치면 비로소 java 가 되므로 true 로 바꿈
        }
        // cpp
        else if (str[i] == '_')
        {
            // '_' 가 들어간 경우
            if (!i || isJava || i == str.length() - 1 || str[i + 1] == '_' || isupper(str[i + 1]))
            { // 첫글자 이거나, 자바이거나, 끝 - 1 이거나(i + 1 번째에 대한 연산 필요), 다음글자에 _가 있거나 (연속된 '_' 가 오는 경우), 다음 문자가 대문자('_' 다음에 대문자가 온다는 뜻) 이거나 하면 오류다
                isError = true;
                break;
            }
            // 소문자로 바꿔서 삽입
            result += str[i + 1] - 'a' + 'A';
            i++;
            isCpp = true; // 위 과정을 다 거치면 비로소 cpp 가 되므로 true 로 변경
        }
        else
        {
            // 대문자나 '_' 둘다 아닌 경우 (소문자 일때) 는 그냥 삽입
            result += str[i];
        }
    }

    if (isError)
        cout << "Error!\n";
    else
        cout << result << '\n';

    return 0;
}

/*
    문자열 문제를 풀때는
    1. 기존 알고리즘을 이용하는가 (KMP, RabinKarp 등) 을 사용하는지 파악하고
    2. 단순한 ascii 코드 연산을 통해서 구할 수 있는가 를 파악하고
    3. 예외처리를 얼마나 섬세하게 하는가가 중요함.
*/