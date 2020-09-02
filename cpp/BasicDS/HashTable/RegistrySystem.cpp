/*
    C. Registration System
    
    문제 : https://codeforces.com/contest/4/problem/C
    
    풀이 : https://github.com/gyoogle/tech-interview-for-developer/blob/master/Algorithm/Hash%20Table%20%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0.md
*/

#include <iostream>
#define HASH_SIZE 1000  // HASH_SIZE, HASH_LEN 두가지로 나뉜 이유는 문제의 전체 크기가 십만이기 때문이다.
#define HASH_LEN 400    // 이 값은 400 이 아니라 더 작은 값도 된다 (십만의 크기를 갖는 일차원 배열 대신 이차원 배열로 나눈것.)
#define HASH_VAL 5      // 이 값은 해시를 만들기 위해서 쓰이는 값으로 꼭 5가 아니어도 '소수' 인 수 아무거나 하면 된다.

using namespace std;

string str;
int N;
int arr[HASH_SIZE][HASH_LEN];        // 특정 문자열이 중복된게 몇개가 있는지 세기 위한 이차원 배열
string s_data[HASH_SIZE][HASH_LEN];  // 문자열이 저장될 이차원 배열
int length[HASH_SIZE];               // 동일한 키 값이 몇번 나왔는지 카운팅 하기 위한 일차원 배열

int check(int key) {
    // 동일한 문자열이 몇번 나왔는지 카운팅
    int len = length[key];

    if (len != 0) {
        for (int i = 0; i <= len; i++) {
            if (s_data[len][i] == str) {
                arr[len][i]++;
                return arr[len][i];
            }
        }
    }

    s_data[key][length[key]++] = str;

    return -1;
}

int get_hash_key(string str) {
    // 키 값을 해시로 만드는 해시 함수
    int key = 0;
    int size = str.size();
    for (int i = 0; i < size; i++) {
        char ch = str[i];
        key = (key * HASH_VAL) + ch + HASH_VAL;
    }
    if (key < 0) key *= -1;
    return key % HASH_SIZE;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> str;
        int key = get_hash_key(str);
        int cnt = check(key);

        if (cnt != -1) {
            cout << str << cnt << '\n';
        } else {
            cout << "OK" << '\n';
        }
    }

    return 0;
}