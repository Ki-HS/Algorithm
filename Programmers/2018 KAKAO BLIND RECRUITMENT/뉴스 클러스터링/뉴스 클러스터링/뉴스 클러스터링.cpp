#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;

int slv(map<string, int> a, map<string, int> b) {

    float d;

    map<string, int> sum, com;
    for (auto i = a.begin(); i != a.end(); i++) {
        sum[i->first] += i->second;
    }
    for (auto i = b.begin(); i != b.end(); i++) {
        if (sum[i->first]) { sum[i->first] = (sum[i->first] <= i->second)? i->second: sum[i->first]; continue; }
        sum[i->first] += i->second;
    }

    for (auto i = a.begin(); i != a.end(); i++) {
        if (b[i->first] == 0)continue;
        (b[i->first] > i->second) ? com[i->first] += i->second : com[i->first] += b[i->first];
    }
    double max = 0;
    double min = 0;
    for (auto i = sum.begin(); i != sum.end(); i++) {
        max += i->second;
    }
    for (auto i = com.begin(); i != com.end(); i++) {
        min += i->second;
    }
    d = min / max;
    if (max == min)return 65536;
    d *= 65536;
    return d;

}

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m1, m2;

    for (int i = 0; i < str1.size() - 1; i++) {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1]))continue;
        string t = "";
        t += str1[i];
        t+=str1[i + 1];
        std::transform(t.begin(), t.end(), t.begin(), ::tolower);
        m1[t]++;
    }

    for (int i = 0; i < str2.size() - 1; i++) {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1]))continue;
        string t = "";
        t += str2[i];
        t+=str2[i + 1];
        std::transform(t.begin(), t.end(), t.begin(), ::tolower);
        m2[t]++;
    }
    return (m1.size() > m2.size()) ? slv(m2, m1) : slv(m1, m2);;
}

int main() {
    cout << solution("aaaaaaa", "aa");
}