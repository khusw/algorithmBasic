/*
    문자열에 관한 기본적인 함수 및 각종 사용법을 정리한 파일

    문자열 분리, 문자열 합치기, 부분 문자열 발견하기 등 을 차차 기록해 나갈 파일임.
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// istringstream 을 활용한 문자열 구분
void IStringStream(string str) {
    istringstream ss(str);
    string strBuffer;
    while (getline(ss, strBuffer, ' ')) {
        // getline 에 delimiter 를 넣을 때 주의할 점은
        // "" 과 '' 는 다르다는 점이다.
        // "" 는 string 을 '' 는 char 를 의미한다
        // getline 의 delimiter 는 char 가 들어가야 한다.
        cout << strBuffer;
    }
}

// string 의 find 를 이용한 구분
void find(string str) {
    if (str.find("is") == string::npos) {
        // find 함수는 해당 문자열이 처음 나오는 인덱스 번호를 리턴한다
        // find 함수로 찾지 못한 경우 string::npos 를 리턴한다.
        cout << "찾는 문자열이 없다" << '\n';
    } else {
        cout << str.find("is") << "index 에서 찾았다" << '\n';
    }
}

int main() {
    string str = "This is String";
    string str2 = "This is good";
    IStringStream(str);

    const char* ch = str.c_str();  // c_str 의 반환 타입은 const char* 이다. (char 가 아님)

    str.push_back('c');  // push_back 에 들어가는 인자 값은 char type 이다. (const char* 가 아님에 유의)

    int result = str.compare(str2);  // 두 문자열에 대한 compare 함수의 결과는 음수, 0, 양수 임
    // 음수는 사전적으로 앞, 0은 동일, 양수는 사전적으로 뒷 값 이란 뜻  a.compare(b) 하면 결과가 -1
    cout << result << '\n';

    return 0;
}