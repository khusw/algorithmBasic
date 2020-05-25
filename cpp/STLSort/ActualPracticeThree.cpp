/*
    코테에서는 STL 을 많이 알 수록 도움이 된다 (java, js 는 collection)
    앞선 예제들에서는 한 쌍의 데이터가 들어오면, 그 중 하나를 선정해서 정렬하는 방식을 알아 봤다
    그러면 여기서는 3개의 데이터가 들어올 때, 2개의 기준을 가지고 데이터를 정렬하는 방법에 대해서 파악해 본다.

    "학생을 나타내는 정보가 이름, 성적, 생년월일 이 주어질때, 학생을 성적순으로 나열하려한다.
    이때, 성적이 동일하면, 나이가 어린 학생이 더 우선순위를 높게 갖도록 지정해라." 라는 문제를 처리한다 하면,
    기준 점이 두개인것이다. 성적, 나이 라는 기준점이 작용하며, 이를 어떻게 코드로 작성하는가
    vector 와 pair 를 사용해 처리해 본다.

    여기서의 pair 는 이중 pair 가 사용된다(pair 안의 pair)
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b)
{
    // 이름, 성적, 생년월일 순
    if (a.second.first == b.second.first)
    {                                             // second.first 는 성적을 의미함.
        return a.second.second > b.second.second; // 성적이 같은 경우 생년월일이 더 어린 사람이 더 큰 우선순위를 갖게함
        // 연도 수의 크기가 작을 수록 더 나이가 많은 사람이란 뜻임. 1994 < 1995, 그래서 부호가 a.sec.sec > b.sec.sec 임.
    }
    else
    {
        return a.second.first > b.second.first;
    }
}

int main()
{
    vector<pair<string, pair<int, int>>> v; // 이름, 성적, 생년월일 순
    v.push_back(pair<string, pair<int, int>>("kim", pair<int, int>(10, 20191104)));
    v.push_back(pair<string, pair<int, int>>("shin", pair<int, int>(20, 20181209)));
    v.push_back(pair<string, pair<int, int>>("park", pair<int, int>(40, 20170624)));
    v.push_back(pair<string, pair<int, int>>("lee", pair<int, int>(40, 20181104)));
    v.push_back(pair<string, pair<int, int>>("jin", pair<int, int>(35, 20160321)));

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << '\n'; // cpp shell 에서는 이부분이 출력이 잘 됨 (아마도 vscode c++ compiler 에 문제가 있음)
    }
    return 0;
}

/*
    코테에서 정렬 기준이 여러개인 문제가 종종 나온다.
    그때는 이것 처럼 pair 를 사용하고, sort 를 사용해서 문제를 해결하면, 답을 맞출 수 있을거 같다.
    정렬 기준이 3개 이상이 되면 pair 가 오히려 더 복잡해 질 수 있기 때문에, 차라리 class 를 쓰는게 더 나을 수 있다.
*/
