#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
map<char, int> m;

char ans(char x, char y) {
    if (m[x] > m[y])return x;
    else if (m[x] < m[y]) return y;
    else {
        if (x < y)return x;
        else return y;
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] == 4)continue;
        else if (choices[i] < 4) m[survey[i][0]] += abs(4 - choices[i]);
        else m[survey[i][1]] += abs(4 - choices[i]);
    }

    answer += ans('R', 'T');
    answer += ans('C', 'F');
    answer += ans('J', 'M');
    answer += ans('A', 'N');


    return answer;
}