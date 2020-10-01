/*
    BOJ 5397 키로거
    https://www.acmicpc.net/problem/5397

    KeyLogger 란 컴퓨터 상에서 입력하는 모든 입력을 가져와서 탈취하는 방법 중 하나이다.

    입력의 첫번째 줄에 테스트 케이스가 주어지고 최대 백만 까지가 입력된다.

    각 테스트 케이스 별로 문자열이 입력으로 들어오는데, 이때 문자들은 서로 다른 L 의 길이를 갖는다.
    이때, L 은 1 ~ 백만 사이의 값을 갖는 길이이다.
    만약 Back Space 를 입력으로 넣는다면 그때의 문자는 '-' 가 들어오며, 
    스택 구조상 - 앞에 어떤 글자가 존재하면 그 글자를 지우게 되어 있다.

    화살표의 입력은 <, > 으로 주어지며, 이 화살표는 커서의 위치를 왼쪽 또는 오른쪽으로 1 씩 움직이는 것을 의미한다.

    화살표 문자와 백스페이스 문자를 제외한 다른 모든 문자들은 비밀번호의 일부 값이 된다
    즉, 출력해야될 대상이 된다는 뜻.
*/
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        string L;
        cin >> L;

        list<char> ans;
        list<char>::iterator ans_iter = ans.begin();

        int L_len = L.size();
        int L_idx = 0;

        while (L_idx < L_len) {
            switch (L[L_idx]) {
                case '<':
                    if (ans_iter != ans.begin())
                        ans_iter--;
                    break;
                case '>':
                    if (ans_iter != ans.end())
                        ans_iter++;
                    break;
                case '-':
                    if (ans_iter != ans.begin())
                        ans.erase((--ans_iter)++);
                    break;
                default:
                    ans.insert(ans_iter, L[L_idx]);
                    break;
            }
            L_idx++;
        }
        for (auto x : ans)
            printf("%c", x);
        printf("\n");
    }
    return 0;
}