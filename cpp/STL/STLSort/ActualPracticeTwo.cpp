/*
    클래스를 사용해서 데이터를 정렬하는 방식은 
    필드에 나가서나 유용한 방식이며, 프로그래밍 대회 같은 곳(또는 코딩테스트) 에서는
    클래스를 직접사용하면 메모리도 많이쓰고, 시간적으로 오래 걸리기 때문에,
    코테 같은데서는 잘 안쓰나보다 (하긴 여태까지 클래스를 쓰는 코테는 본적이 없다)
    그래서 코테를 위한 sort 를 어떻게 쓰는지 알아본다 (여기선 pair 를 쓴다고한다.)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, string>> v;
    v.push_back(pair<int, string>(90, "kim")); // int 와 string 형식의 데이터를 한쌍으로 넣는 법
    v.push_back(pair<int, string>(80, "lee"));
    v.push_back(pair<int, string>(70, "park"));
    v.push_back(pair<int, string>(95, "song"));
    v.push_back(pair<int, string>(75, "kang"));
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << '\n'; // pair 데이터를 출력하기 위해서는 pair.first, pair.second 같은 방식으로 뽑아야함.
        // v[i].second 라 하면 i 번째의 두 번째 요소 즉, 이름을 출력하는 것.
    }
    // 위에 까지는 아무런 정렬이 이뤄진 상태가 아니기 때문에, 순서대로 쭉 출력된다.
    sort(v.begin(), v.end()); // 여기서의 정렬 기준은 pair 의 첫번째 first 를 기준으로 정렬된다 (점수순)
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << '\n';
    }
}

/*
    벡터는 기본적으로 연결리스트를 기반으로한 개념이다.
    pair 는 한쌍의 데이터를 다루기 위해 사용되는 라이브러리다.
*/