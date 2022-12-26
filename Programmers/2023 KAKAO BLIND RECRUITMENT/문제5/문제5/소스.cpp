#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<vector<string>> v(50, vector<string>(50, ""));

bool isMerge(map<pair<int, int>, pair<int, int>> m, int r, int c) {
    pair<int, int> tPair = make_pair(r, c);
    if (m.find(tPair) != m.end())return true;
    return false;
}


void mUpdate(map<pair<int, int>, pair<int, int>> &m, int r, int c, string val) {
    pair<int, int> p = m[make_pair(r, c)];
    int x= p.first;
    int y = p.second;

    v[x][y] = val;
}

void mMerge(map<pair<int, int>, pair<int, int>> &m, int x1, int y1, int x2, int y2) {

    if (isMerge(m, x1, y1)) {
        pair<int, int> p = m[make_pair(x2, y2)];
        pair<int, int> p2=m[make_pair(x1, y1)];
        if (v[p2.first][p2.second] == "" && v[p.first][p.second] != "")v[x1][y1] = v[p.first][p.second];
        for (auto &i : m) {
            if (i.second == p) {
                i.second = p2;
            }
        }
    }
    else {
        pair<int, int> p;
        pair<int, int> p2(x1, y1);
        if (isMerge(m, x2, y2))p = m[make_pair(x2, y2)];
        else {
            m[make_pair(x2, y2)] = p2; 
            if (v[x1][y1] == "" && v[x2][y2] != "")v[x1][y1] = v[x2][y2];
            return;
        }
        if (v[x1][y1] == "" && v[p.first][p.second] != "")v[x1][y1] = v[p.first][p.second];
        m[p] = p2;
        for (auto &i : m) {
            if (i.second == p) {
                i.second = p2;
            }
        }
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    map<pair<int, int>, pair<int, int>> m;
    for (auto i : commands) {
        vector<string> vs;
        stringstream sstream(i);
        string temp;
        while (sstream >> temp)vs.push_back(temp);
        if (vs[0] == "UPDATE") {
            if (vs.size() == 4) {
                int x = stoi(vs[1]) - 1;
                int y = stoi(vs[2]) - 1;
                if (isMerge(m, x, y)) {
                    mUpdate(m, x, y, vs[3]);
                }
                else
                    v[x][y] = vs[3];
            }
            else {
                for (int i = 0; i < 50; i++) {
                    for (int j = 0; j < 50; j++) {
                        if (v[i][j] == vs[1]) {
                            v[i][j] = vs[2];
                        }
                    }
                }
            }
        }
        else if (vs[0] == "MERGE") {
            int x1 = stoi(vs[1])-1;
            int y1 = stoi(vs[2]) - 1;
            int x2 = stoi(vs[3]) - 1;
            int y2 = stoi(vs[4]) - 1;

            if (isMerge(m, x2, y2)||isMerge(m,x1,y1)) {
                if (m.find(make_pair(x1, y1)) != m.end()) {
                    pair<int, int> p = m[make_pair(x1, y1)];
                    mMerge(m, p.first, p.second, x2, y2);
                }
                else {
                    mMerge(m, x1, y1, x2, y2);
                }
            }
            else {
                pair<int, int> p1(x1, y1);
                pair<int, int> p2(x2, y2);
                if (v[x1][y1] == "" && v[x2][y2] != "")v[x1][y1] = v[x2][y2];
                m[p2] = p1;
            }
        }
        else if (vs[0] == "UNMERGE") {
            int x = stoi(vs[1]) - 1;
            int y = stoi(vs[2]) - 1;
            pair<int, int> p;
            if (m.find(make_pair(x,y))!=m.end()) {
                 p= m[make_pair(x, y)];
            }
            else p=make_pair(x, y);
            string tStr = v[p.first][p.second];
            vector<pair<int, int>> vp;
            for (auto i : m) {
                if (i.second == p) {
                    v[i.first.first][i.first.second] = "";
                    vp.push_back(i.first);
                }
            }
            for (auto i : vp) {
                m.erase(i);
            }
            v[x][y] = tStr;
        }
        else {//PRINT
            int x = stoi(vs[1]) - 1;
            int y = stoi(vs[2]) - 1;
            if (isMerge(m, x, y)) {
                pair<int, int> p = m[make_pair(x, y)];
                if (v[p.first][p.second] == "")answer.push_back("EMPTY");
                else answer.push_back(v[p.first][p.second]);
            }
            else {
                if(v[x][y]=="")answer.push_back("EMPTY");
                else answer.push_back(v[x][y]);
            }
        }
    }
    return answer;
}

int main() {
    vector<string> cmd = { "UPDATE 1 1 A", "UPDATE 1 2 B","UPDATE 2 1 C", "UPDATE 2 2 D", "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1" };
    vector<string> cmd2 = { "UPDATE 1 1 MENU","UPDATE 1 2 CATEGORY", "UPDATE 2 1 VIVI", "UPDATE 2 2 KOR", "UPDATE 2 3 RICE", "UPDATE 3 1 RAM", "UPDATE 3 2 KOR", "UPDATE 3 3 NOOD", "UPDATE 3 4 INSTANT","UPDATE 4 1 PASTA", "UPDATE 4 2 ITALIAN","UPDATE 4 3 NOOD","MERGE 1 2 1 3","MERGE 1 3 1 4","MERGE 1 1 1 3", "UPDATE KOR HAN", "UPDATE 1 3 GRP","UNMERGE 1 4","PRINT 1 3", "PRINT 1 4"};
    
    solution(cmd2);
}