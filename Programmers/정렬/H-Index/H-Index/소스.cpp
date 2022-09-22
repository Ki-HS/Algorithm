#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> c) {
    int answer = 0;
    sort(c.begin(), c.end());
    int prev = 0;
    for (int i = 1; i <= c.size(); i++) {
        for (int j = 0; j < c.size(); j++) {
            if (c[j] >= i && c.size() - j >= i && j <= i)answer = i;
        }
    }
    return answer;
}