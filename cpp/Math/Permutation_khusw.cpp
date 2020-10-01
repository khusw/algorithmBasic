/*
    순열을 표현한 cpp 코드
    순열은 순서가 있는 n 개의 원소들에 대해서 
    모든 경우의 수를 전부 구하는 방법임
    원소 {1,2,3} 이 주어지면,
    이를 나열하기 위한 모든 경우의 수는
    
    1,2,3
    1,3,2
    2,1,3
    2,3,1
    3,1,2
    3,2,1

    총 6가지로 3! 가 된다.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> vec = {1, 2, 3};

void permutation(int start, int end) {
    if (start == end) {
        for (auto it : vec) {
            cout << it << " ";
        }
        cout << '\n';
    } else {
        for (int i = start; i <= end; i++) {
            swap(vec[start], vec[i]);
            permutation(start + 1, end);
            swap(vec[start], vec[i]);
            // swap 을 이렇게 두번 수행하는 이유는 다음 차례에서 원상복귀 시킨 상태에서 다시 연산하기 위함이다.
            // 예를 들면, P = [1,2,3,4,5] 일 때,
            // [1,2,3,5,4] 로 swap 연산이 이뤄졌으면 그 다음엔 [1,2,4,3,5] 가 되야 하므로
            // [1,2,3,4,5] 로 다시 바꿔줘야 다음 차례에서 이에 대한 연산을 제대로 수행할 수 있기 때문
        }
    }
}

int main() {
    permutation(0, 2);
    return 0;
}