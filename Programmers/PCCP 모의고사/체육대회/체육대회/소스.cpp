#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<vector<int>> a) {
    int answer = 0;
    vector<int> v(a[0].size(), 0);
    vector<int> s(a[0].size(), 0);
    for (int i = 0; i < s.size(); i++)s[i] = i;
    int sum = 0;
    do {
        int t = 0;

        map<int, int> m;
        for (int j = 0; j < s.size(); j++) {
            int q;
            int max = 0;
            for (int i = 0; i < a.size(); i++) {
                if (m[i] == 0 && a[i][s[j]] > max) {
                    q = i;
                    max = a[i][s[j]];
                }
            }
            m[q]++;
            t += max;
        }
        if (sum < t)sum = t;
    } while (next_permutation(s.begin(), s.end()));

    return sum;
}