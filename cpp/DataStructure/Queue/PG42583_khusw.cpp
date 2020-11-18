/*
    PG 42583 다리를 지나는 트럭
    https://programmers.co.kr/learn/courses/30/lessons/42583
*/

#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> count_queue, length_queue;  // 다리에 들어간 트럭수, 남은시간
    int sum = 0, time = 0;

    while (1) {
        int size = length_queue.size();  // 다리에 진입한 트럭들의 시간을 하나씩 빼주기 위한 코드
        for (int i = 0; i < size; ++i) {
            int length = length_queue.front();
            length_queue.pop();
            if (length <= 1) {
                sum -= count_queue.front();
                count_queue.pop();
                continue;
            }
            length_queue.push(length - 1);
        }
        if (truck_weights.size() > 0 && sum + truck_weights[0] <= weight) {  // 대기 차량이 있으면서 다리에 진입할 수 있을때
            count_queue.push(truck_weights[0]);
            length_queue.push(bridge_length);
            sum += truck_weights[0];
            truck_weights.erase(truck_weights.begin());
        }
        time++;
        if (truck_weights.size() == 0 && count_queue.size() == 0) break;  // 대기 차량도 없고 다리에도 차가 없을때
    }

    answer = time;
    return answer;
}