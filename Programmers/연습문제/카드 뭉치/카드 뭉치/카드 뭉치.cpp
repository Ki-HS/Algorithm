#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";

    int i, j;
    i = j = 0;
    for (string s : goal) {
        if (cards1[i] == s)i++;
        else if (cards2[j] == s)j++;
        else break;
    }
    return (i + j < goal.size()) ? "No" : "Yes";
}