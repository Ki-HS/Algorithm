#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(vector<int> array, int n) {
    int answer = 1010;
    sort(array.begin(), array.end(), greater<>());
    for (auto i : array) {
        answer = (abs(answer - n) < abs(i - n)) ? answer : i;
    }
    return answer;
}