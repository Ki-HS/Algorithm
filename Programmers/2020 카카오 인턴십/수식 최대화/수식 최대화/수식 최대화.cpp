#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long solution(string exp) {
    long long answer = 0;

    vector<char> op;
    vector<long long> num;

    string s = "";
    map<char, int> m;
    for (int i = 0; i < exp.size(); i++) {
        if (exp[i] > '9' || exp[i] < '0') {
            op.push_back(exp[i]);
            m[exp[i]]++;
            num.push_back(stoll(s));
            s = "";
            continue;
        }
        s += exp[i];
    }
    num.push_back(stoll(s));


    vector<char> seq;
    for (auto i = m.begin(); i != m.end(); i++)
        seq.push_back(i->first);

    do {
        vector<char> tp = op;
        vector<long long> np = num;
        while (tp.size()) {
            if (find(tp.begin(), tp.end(), seq[0]) != tp.end()) {
                int idx = find(tp.begin(), tp.end(), seq[0]) - tp.begin();
                if (tp[idx] == '*') np[idx] *= np[idx + 1];
                else if (tp[idx] == '+') np[idx] += np[idx + 1];
                else np[idx] -= np[idx + 1];
                tp.erase(tp.begin() + idx);

                np.erase(np.begin() + idx + 1);
            }
            else if (find(tp.begin(), tp.end(), seq[1]) != tp.end()) {
                int idx = find(tp.begin(), tp.end(), seq[1]) - tp.begin();
                if (tp[idx] == '*') np[idx] *= np[idx + 1];
                else if (tp[idx] == '+') np[idx] += np[idx + 1];
                else np[idx] -= np[idx + 1];
                tp.erase(tp.begin() + idx);
                np.erase(np.begin() + idx + 1);
            }
            else if (seq.size() > 2 && find(tp.begin(), tp.end(), seq[2]) != tp.end()) {
                int idx = find(tp.begin(), tp.end(), seq[2]) - tp.begin();
                if (tp[idx] == '*') np[idx] *= np[idx + 1];
                else if (tp[idx] == '+') np[idx] += np[idx + 1];
                else np[idx] -= np[idx + 1];
                tp.erase(tp.begin() + idx);
                np.erase(np.begin() + idx + 1);
            }
        }
        answer = (answer < abs(np[0])) ? abs(np[0]) : answer;
    } while (next_permutation(seq.begin(), seq.end()));

    return answer;
}