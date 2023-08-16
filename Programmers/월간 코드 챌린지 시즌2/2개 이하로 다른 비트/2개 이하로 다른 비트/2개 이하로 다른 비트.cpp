#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (long long n : numbers) {
        if (n % 2 == 0) answer.emplace_back(n + 1);
        else {
            long long t = 2;
            long long target = n - 1;
            while (target <= n) {
                target = n ^ t;
                if (target < n) {
                    target ^=t;
                    t <<= 1;
                }
                else target ^= (t >>= 1);
            }
            answer.emplace_back(target);
        }
    }
    return answer;
}

int main() {
    solution({ 2,7 });
}