#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> v(n, 1);
    map<int, int> m;
    for (auto i : reserve)v[i - 1]++;
    for (auto i : lost)v[i - 1]--;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (i && v[i - 1] > 1 && v[i] == 0) {
            v[i - 1]--;
            v[i]++;
        }
        else if (v[i + 1] > 1 && v[i] == 0) {
            v[i + 1]--;
            v[i]++;
        }

        if (j != n - 1 && v[j + 1] > 1 && v[j] == 0) {
            v[j + 1]--;
            v[j]++;
        }
        else if (j - 1 != i + 1 && v[j - 1] > 1 && v[j] == 0) {
            v[j - 1]--;
            v[j]++;
        }
        i++;
        j--;
    }
    for (auto i : v) {
        if (i)answer++;
    }

    return answer;
}