#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>


using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;
    string prev;
    for (int i = 0; i < words.size(); i++) {
        if (i != 0 && prev[prev.size() - 1] != words[i][0]) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        m[words[i]]++;
        if (m[words[i]] > 1) {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        prev = words[i];

    }


    return { 0,0 };
}