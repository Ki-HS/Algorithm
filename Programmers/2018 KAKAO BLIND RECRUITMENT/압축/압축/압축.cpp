#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    map<string, int> dict;
    for (int i = 0; i < 26; i++) {
        string c = "A";
        c[0] += i;
        dict[c] = i + 1;
    }

    int total = 26;

    for (int i = 0; i < msg.size(); i++) {
        string temp = "";
        temp+=msg[i];
        string prev = temp;
        int idx = 0;

        while (dict[temp]) {
            idx++;
            prev = temp;

            if (i + idx == msg.size()) break;
            temp += msg[i + idx];
        }
        answer.push_back(dict[prev]);

        //마지막 추가한 글자의 인덱스가 주어진 단어의 마지막 단어가 아니면
        if (temp != prev) {
            dict[temp] = ++total;
        }
        i += idx-1;
    }
    return answer;
}

int main() {
    solution("KAKAO");
}