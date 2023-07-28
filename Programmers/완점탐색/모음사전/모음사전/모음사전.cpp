#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int solution(string word) {
    int answer = 0;

    map<char, int> m;
    m['A'] = 1;
    m['E'] = 2;
    m['I'] = 3;
    m['O'] = 4;
    m['U'] = 5;

    for()

    for (int i = 0; i < word.size(); i++) {
        if (i == 4) {
            answer += m[word[i]]; break;
        }
        if (word[i] == 'A') answer += 1;
        else { 
            
            answer += (m[word[i]] - 1) * pow(5, 5 - (i + 1)); }
    }
    return answer;
}

int main() {
    cout<<solution("AAAE");
}