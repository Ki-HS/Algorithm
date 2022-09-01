#include <vector>
#include <iostream>
using namespace std;

int answer = 0;
int depth = 3;

void combination(vector<int> nums, vector<int> sum, int idx, int r, int d) {
    if (r == depth) {
        int s = sum[0] + sum[1] + sum[2];
        for (int i = 2; i <= s / 2; i++) {
            if (s % i == 0)return;
        }
        answer++;
        return;
    }
    if (d == nums.size())return;
    sum[idx] = nums[d];
    combination(nums, sum, idx + 1, r + 1, d + 1);
    combination(nums, sum, idx, r, d + 1);
}

int solution(vector<int> nums) {
    vector<int> sum(nums.size());
    combination(nums, sum, 0, 0, 0);

    return answer;
}

int main() {
    vector<int> v = { 1,2,7,6,4 };
    int a = solution(v);
    cout << a;
}