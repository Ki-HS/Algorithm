#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<string> solution(vector<vector<int>> q) {
    vector<string> answer;
    for (auto i : q) {
        int l = i[0];
        int a = i[1] / 4;
        int b = i[1] % 4;
        if (b == 0)a--;
        if (l == 1) {
            answer.push_back("Rr");
            continue;
        }

        stack<int> s;
        while (l != 1) {
            s.push(b);
            b = (a + 1) % 4;
            a = (a + 1) / 4;
            if (b == 0)a--;

            l--;
        }

        string prop = "Rr";
        while (s.size()) {
            int order = s.top();
            s.pop();
            if (prop == "Rr") {
                if (order == 1) prop = "RR";
                else if (order == 4 || order == 0) prop = "rr";
                else prop = "Rr";
            }
        }
        answer.push_back(prop);
    }
    return answer;
}