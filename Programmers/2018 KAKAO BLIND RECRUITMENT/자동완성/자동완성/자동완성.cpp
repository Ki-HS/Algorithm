#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(string a, string b) {
    int i = 0;

    for (; i < a.size(); i++) {
        if (a[i] != b[i]) break;
    }

    return i;
}

int solution(vector<string> words) {
    int answer = 0;

    sort(words.begin(), words.end());

    int t = cmp(words[0], words[1]);
    answer += words[0].size() ==t ? words[0].size() : t + 1;

    for (int i = 1; i < words.size()-1; i++) {
        int cntA = cmp(words[i - 1], words[i]);
        int cntB = cmp(words[i], words[i+1]);
        answer += cntA > cntB ? cntA : cntB==words[i].size()? cntB-1:cntB;
        answer++;
    }

    t = cmp(words[words.size()-2], words.back());
    answer += t + 1;

    return answer;
}

int main() {
    cout << solution({ "ab", "abc" });
}