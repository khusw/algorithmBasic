/*
    PG 12949 행렬의 곱셈
    https://programmers.co.kr/learn/courses/30/lessons/12949#
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int row = arr1.size(), col = arr2[0].size();
    vector<vector<int>> answer(row, vector<int>(col, 0));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int num1, num2, sum = 0;
            for (int k = 0; k < arr1[0].size(); ++k) {
                num1 = arr1[i][k];
                num2 = arr2[k][j];
                sum = sum + (num1 * num2);
            }
            answer[i][j] = sum;
        }
    }

    return answer;
}