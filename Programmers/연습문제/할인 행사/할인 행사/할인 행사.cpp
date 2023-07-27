#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool cmp(map<string, int> a, map<string, int>b) {
    for (auto i = a.begin(); i != a.end(); i++) {
        if (i->second != b[i->first]) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    map<string, int> dis;
    for (int i = 0; i < want.size(); i++) {
        m[want[i]] = number[i];
        dis[want[i]] = 0;
    }

    int i = 0;
    for (i = 0; i < 10; i++) {
        dis[discount[i]]++;

    }

    while (i != discount.size()) {

        if (cmp(m, dis)) answer++;

        dis[discount[i - 10]]--;
        dis[discount[i]]++;
        i++;
    }
    if (cmp(m, dis)) answer++;

    return answer;
}

int main() {
    solution(
        { "banana", "apple", "rice", "pork", "pot" },
        { 3, 2, 2, 2, 1 },
        { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" }
    );
}