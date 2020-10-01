/*
    BOJ 1919 애너그램 만들기
    https://www.acmicpc.net/problem/1919

    두 영어 단어가 주어질때 철자의 순서를 뒤바꿔서 같아지게 되면,
    그 두 단어를 애너그램 관계에 있다고 부른다
    occurs 와 succor 는 애너그램 관계에 있다.
    당장 둘을 서로 뒤집으면, 같은 단어가 되는 것은 아니지만,
    순서를 바꾸면 애너그램 관계로 만들 수 있기 때문이다.

    만약 두 단어로, dared, bread 가 주어진 경우 
    이 두 단어는 애너그램 관계가 되지 못한다.
    하지만, dared 에서 d 지우고, bread 에서 b 지우면 ared, read 가 남아서
    애너그램 관계를 형성할 수 있게 된다.

    문제의 입력으로 두개의 영단어가 주어졌을 때, 두 단어를 애너그램 관계로 만들기 위해
    제거해야할 최소 갯수의 문자 수를 구하는 프로그램을 작성해야한다.
    (문자 제거시에는 아무 위치에 있는 문자든 제거 가능하다)

    입력은 두줄에 걸쳐서 영어단어가 소문자로 주어진다.
    각 단어의 최대 길이는 1000자 이하이다.

    출력은 애너그램 관계 형성을 위해 제거해야될 문자의 최소 갯수를 구하면 된다.
*/

#include <iostream>
#include <string>

using namespace std;

int alphabet1[26], alphabet2[26];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str1, str2;
    cin >> str1 >> str2;

    // 아래의 두 for 문은 각 str 이 포함한 알파벳이 몇개인지 표현하기 위해
    // 아스키 코드를 사용한 연산을 통해서 증감 연산자를 통해 해당 알파벳 갯수를 표현함.
    for (int i = 0; i < str1.size(); i++)
    {
        alphabet1[str1[i] - 'a']++;
    }

    for (int j = 0; j < str2.size(); j++)
    {
        alphabet2[str2[j] - 'a']++;
    }

    // 알파벳 갯수를 초기화 한 이후, 서로 다른 갯수를 가진 경우나 다른 알파벳을 가진경우 카운팅을 시작하고
    // 그때의 카운팅 방식은 절댓값 연산을 통해서 둘을 뺀 값을 카운팅 횟수에 추가한다.
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet1[i] != alphabet2[i])
        {
            cnt += abs(alphabet1[i] - alphabet2[i]);
        }
    }

    cout << cnt;

    return 0;
}