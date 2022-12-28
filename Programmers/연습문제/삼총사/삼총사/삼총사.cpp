#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    vector<int> v(number.size(), 1);
    for (int i = 0; i < 3; i++)v[i] = 0;

    do {
        int sum = 0;

        for (int i = 0; i < v.size(); i++) {
            if (v[i]==0) {
                sum += number[i];
            }
        }
        if (sum == 0)answer++;
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}

int main() {
    cout << solution({ -2, 3, 0, 2, -5 });
}
