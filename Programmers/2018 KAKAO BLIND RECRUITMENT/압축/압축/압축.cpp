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

        //������ �߰��� ������ �ε����� �־��� �ܾ��� ������ �ܾ �ƴϸ�
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