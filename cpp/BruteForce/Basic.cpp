/*
    Brute Force (완전 탐색)

    알고리즘의 이름이 완전 탐색 이긴 하지만,
    PS 로 나오는 문제들은 단순 무식하게 O(N^2), O(N^3) .. 같은 엄청나게 큰 시간 복잡도로 코드를 짤 경우 통과를 못한다
    완전 탐색을 하긴 하되, O(NlogN) 으로 돌린다던가 하는식으로
    최대한 시간 복잡도를 줄이는게 관건이다.

    문제에서 입력 N 이 1000 이하인 경우엔 O(N^2) 까지 가능하긴 하지만,
    이보다도 더 커지면, N 이 10,000 , 100,000 .... 등으로 쭉 높아질때는
    O(N^2) 은 불가능하다.

    아주 간단한 예제로,
    N 개의 수를 입력받아서, 서로 다른 2개를 더해서 나올 수 있는 합 중 가장 큰 것을 구하는 코드
    를 짜면 아래와 같다.
*/

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cout << arr[N - 1] + arr[N - 2];

    return 0;
}

/*
    만약 위의 코드를 

    #include <algorithm>
    #include <iostream>
    
    using namespace std;

    int main()
    {
        int N;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j)
                    result = max(result, arr[i] + arr[j]);
            }
        }
        cout << result;
    }


    위와 같이 짜게 되면, 
    O(N^2) 의 시간이 소요되며, 만약 N 이 10,000 이상이라면,
    시간이 너무 소요되서 반드시 시간 초과를 받을 것이다.

    그래서 결론은 Brute Force 의 핵심은
    시간복잡도를 최대한 줄인 형태에서 전부 탐색할 수 있느냐 이다.
*/