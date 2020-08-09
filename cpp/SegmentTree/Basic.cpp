/*
    Segment Tree 란 
    여러개의 데이터가 연속적으로 존재할때, 특정 범위의 데이터 합을 구하는 방법이다.
    예를 들면, 배열이 주어졌을때, 배열 일부 구간의 합을 가장 빠르게 구하는 방법 등 이 있다.

    배열 데이터가 5 8 7 3 2 5 1 8 9 8 7 3 이 있다고 하면,
    인덱스 1 ~ 10 까지의 합을 구하라하면,
    각 인덱스 값 하나하나를 더하면 된다.
    즉, 연산속도가 O(N) 인 것.
    근데 배열 데이터 갯수가 많아지면 연산의 속도가 느려지므로
    이를 더 빨리 할수있는 방법을 찾으면,
    트리 구조를 활용한다.

    트리는 구조상 두 개씩 나뉘기 때문에 logN 을 소요해서 연산하도록 하는게 가능하다
    
    참고
    https://blog.naver.com/ndb796/221282210534
*/

#include <iostream>
#include <vector>
#define NUM 12

using namespace std;

int a[] = {1, 9, 3, 8, 4, 5, 5, 9, 10, 3, 4, 5};
int tree[4 * NUM];

int init(int start, int end, int node)
{
    if (start == end) return tree[node] = a[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right)
{
    if (left > end || right < start) return 0; // 범위 밖
    if (left <= start && end <= right) return tree[node]; // 범위 안
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int dif)
{
    if (index < start || index > end) return;
    tree[node] += dif;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main()
{
    init(0, NUM - 1, 1);
    cout << "0부터 12까지 합 : " << sum(0, NUM - 1, 1, 0, 12) << '\n';
    cout << "3부터 8까지의 합 : " << sum(3, NUM - 5, 1, 0, 12) << '\n';
    cout << "인덱스 5의 원소를 -5로 수정" << '\n';
    update(0, NUM - 1, 1, 5, -5);
    return 0;
}