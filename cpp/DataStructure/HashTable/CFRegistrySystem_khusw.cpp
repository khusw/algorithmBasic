#include <iostream>
#define HASH_SIZE 1000
#define HASH_LEN 400
#define HASH_VAL 5

using namespace std;

string str;
int N;
int arr[HASH_SIZE][HASH_LEN];
string s_data[HASH_SIZE][HASH_LEN];
int length[HASH_SIZE];

int check(int key) {
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