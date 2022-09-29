#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string a, string b) {
    string temp = b.substr(0, a.size());
    return a == temp;
}

bool solution(vector<string> p) {
    bool answer = true;

    sort(p.begin(), p.end());

    for (int i = 0; i < p.size() - 1; i++) {
        if (check(p[i], p[i + 1])) {
            answer = false;
            return answer;
        }
    }

    return answer;
}