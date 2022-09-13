#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> v = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
    int d = 5;
    for (int i = a - 1; i > 0; i--) {
        if (i == 2)d += 29;
        else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)d += 31;
        else d += 30;
    }
    d += b;

    return v[d % 7 - 1];
}

int main() {
    cout << solution(12, 31);
}