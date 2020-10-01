/*
    BOJ 1157 단어 공부
    https://www.acmicpc.net/problem/1157

    알파벳 문자가 주어질때, 가장 많이 등장하는 알파벳을 출력하는 문제
    최다 알파벳 갯수가 같은게 여러개 있으면, ? 를 출력하도록함
*/

#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;

    cin >> str;

    int str_len = str.size();
    int alphabet_cnt[100] = {
        0,
    };

    for (char ch : str) {
        if ('a' <= ch) ch -= 32;
        alphabet_cnt[ch]++;
    }

    char answer;
    int max_cnt = 0;
    for (int i = 'A'; i <= 'Z'; i++) {
        if (max_cnt < alphabet_cnt[i]) {
            max_cnt = alphabet_cnt[i];
            answer = i;
        } else if (max_cnt == alphabet_cnt[i]) {
            answer = '?';
        }
    }

    printf("%c", answer);

    return 0;
}
/*
    algorithm 헤더에 포함된
    sort 함수는 O(nlogn)
    count 함수는 O(n)
    toupper 함수는 O(n) 의 시간이 소모된다
    그래서 
    for (int i = 0; i < str.size(); i++) {
        cnt = count(..);
    }
    를 하게 되면 O(N^2) 이 되어 시간 초과가 발생한다.

    그러므로 대문자로 바꾸는것, 카운팅 하는 것 전부 일일이 다 짜야 되는것.

    대문자로 바꾸는 것은 아스키 코드값에 의하면
    동일 알파벳의 대문자와 소문자 사이에 숫자 값으로 32가 차이 난다.
    이 점을 이용하면 대문자로 변환이 가능하다

    그리고 카운팅 문제는 char 값이 int 형으로 바뀔때, 아스키 코드값 기반으로
    바뀌기 때문에, 대문자 A 에서 Z 까지의 아스키 코드 값은 65 ~ 90 이다.
    이점에 착안하여 배열을 생성한뒤 배열의 값을 1 늘려주면된다.

*/