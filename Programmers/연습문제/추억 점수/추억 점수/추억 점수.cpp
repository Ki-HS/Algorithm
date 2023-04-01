#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    map<string, int> m;

    for (int i = 0; i < name.size(); i++) {
        m[name[i]] = yearning[i];
    }

    for (vector<string> v : photo) {
        int t = 0;
        for (string s : v) {
            t += m[s];
        }
        answer.push_back(t);
    }
    return answer;
}