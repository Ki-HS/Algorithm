#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> m;
    for (vector i : clothes) {
        m[i[1]]++;
    }
    long long a = 1;
    for (auto i = m.begin(); i != m.end(); i++) {
        a *= (i->second + 1);
    }
    a--;
    answer = a;

    return answer;
}