#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> v, b;
int E = 0, answer = 100000;

void dfs(int s, int e, vector<string> minerals) {
    if (s == e) {
        int idx = 0;
        int psum = 0;
        for (int i = 0; i < minerals.size(); i++) {
            if (i % 5 == 0 && i != 0) {
                idx++;
            }
            if (idx == b.size()) break;

            int x = b[idx];
            string mineral = minerals[i];
            if (mineral == "diamond") {
                if (x == 0) psum++;
                if (x == 1) psum += 5;
                if (x == 2) psum += 25;
            }
            if (mineral == "iron") {
                if (x == 0) psum++;
                if (x == 1) psum++;
                if (x == 2) psum += 5;
            }
            if (mineral == "stone") {
                if (x == 0) psum++;
                if (x == 1) psum++;
                if (x == 2) psum++;
            }

        }
        answer = min(answer, psum);
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (v[i] > 0) {
            v[i]--;
            b.push_back(i);
            dfs(s + 1, e, minerals);
            b.pop_back();
            v[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int m = minerals.size();
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    for (int i = 0; i < picks.size(); i++) {
        for (int j = 0; j < picks[i]; j++) {
            if (m > 0) {
                E++;
                v[i]++;
                m -= 5;
            }
        }
    }
    dfs(0, E, minerals);
    return answer;
}