#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iterator>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> p) {
    vector<int> answer;

    stringstream sstream(today);
    string word;
    getline(sstream, word, '.');
    int year = stoi(word);
    getline(sstream, word, '.');
    int month = stoi(word);
    getline(sstream, word, '.');
    int day = stoi(word);

    map<char, long> m;

    long now = (year-1) * 12 * 28 + month * 28 + day;

    for (string str : terms) {
        istringstream iss(str);
        string s;
        iss >> s;
        char type = s[0];
        iss >> s;
        int exp = stoi(s) * 28;

        m[type] = now - exp;
    }

    for (int i = 0; i < p.size(); i++) {
        string str = p[i];
        char type = str[str.size() - 1];
        string date = str.substr(0, 10);

        stringstream sstream(date);
        getline(sstream, word, '.');
        year = stoi(word)-1;
        getline(sstream, word, '.');
        month = stoi(word);
        getline(sstream, word, '.');
        day = stoi(word);

        long tmp = year * 12 * 28 + month * 28 + day;

        if (m[type] >= tmp) answer.push_back(i + 1);
    }


    return answer;
}

int main() {
    solution("2022.05.19", { "A 6","B 12","C 3" }, { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" });
}