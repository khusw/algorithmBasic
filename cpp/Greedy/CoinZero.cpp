/*
    BOJ 11047 동전 0

    Greedy 를 활용한 문제.

    준규가 갖고 있는 동전의 종류 N 개.
    각 동전의 갯수는 주어지지 않음 (무한정 많은 것으로 가정)

    이 동전들을 이용해서 가치의 합을 K 로 만들고자 할 때, 최소한으로 필요한 동전의 갯수는?

    N 은 1 ~ 10 
    K 는 1 ~ 1억
    
    입력의 첫째줄에 N 과 K 가 주어지고,
    두번째 줄 입력 부터 N 개 줄에 해당하는 동전의 가치 Ai 가 오름차순으로 주어짐
    Ai 는 1 ~ 백만

    A1 은 무조건 1 이고,
    Ai (i>=2) 에서는 Ai-1 의 배수 형태로 주어짐

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K, cnt;
    cin >> N >> K;

    vector<int> coin_vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> coin_vec[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (K == 0)
        {
            break;
        }

        if (coin_vec[i] > K)
        {
            continue;
        }

        cnt += K / coin_vec[i];
        K %= coin_vec[i];
    }

    return 0;
}

/*
    Greedy 는 현 단계에서 가장 최선의 방법만을 따라서 처리하는 방식이다.
    DP 와 다른 점은 무엇일까?

    DP 는 반복적으로 어떤 일들을 수행할 때,
    메모이제이션 이라는 기법을 활용해서 계산이 중복되는 부분들을 제거하고
    중복되지 않는 부분만 계산해서 처리하자는게 핵심이다.

    DP 는 메모이제이션을 위해서 별도의 메모리 공간이 필요하다.
    그러나 Greedy 는 별도의 메모리 공간을 만들지 않는다. 그냥 현재 가장 적합한 대상만 고르면 되기 때문이다.

    그럼 언제 DP 를 쓰고, 언제 Greedy 를 써야 하는가?
    문제를 보고 입력으로 주어지는 값의 최대값을 봐야 한다.
    이 문제처럼 입력 K의 최대가 1억 정도나 되는 큰 수치인경우
    DP 를 이용해서 메모이제이션을 위한 메모리 할당 시에 메모리 초과 오류가 뜬다.
    그러므로 이런 경우엔 DP 대신에 Greedy 를 써야 하는 것이다.
*/