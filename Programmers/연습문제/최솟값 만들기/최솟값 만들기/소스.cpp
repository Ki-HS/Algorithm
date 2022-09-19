#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int sum = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());
    for (int i = 0; i < A.size(); i++) {
        sum += A[i] * B[i];
    }

    return sum;
}