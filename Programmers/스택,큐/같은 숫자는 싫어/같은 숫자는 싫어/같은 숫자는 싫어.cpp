#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    int cur = 10;
    for (auto i : arr) {
        if (cur != i) {
            answer.push_back(i);
            cur = i;
        }
    }

    return answer;
}