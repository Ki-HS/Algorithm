#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool sort1(int a, int b) {
    return a < b;
}

vector<pair<int, int>> v;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    map<pair<int, int>, int> m;
    for (auto &i : lines) {
        sort(i.begin(), i.end(), sort1);
    }
    for (auto i : lines) {
        for (int j = i[0]; j < i[1]; j++) {
            m[make_pair(j, j + 1)]++;
        }
    }

    for (auto i : m) {
        if (i.second >= 2)answer++;
    }

    return answer;
}

int main() {
    vector<vector<int>> v = { {-10,0},{-1,1},{0,-2} };
    solution(v);
}