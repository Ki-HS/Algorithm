#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int a = stoi(bin1), b = stoi(bin2);
    int t1 = 0, t2 = 0;
    int bi = 1;
    while (a) {
        if (a % 10)t1 += bi;
        a /= 10;
        bi *= 2;
    }
    bi = 2;
    while (b) {
        if (b % 10)t1 += bi;
        b /= 10;
        bi *= 2;
    }
    t1 += t2;
    while (t1) {
        if (t1 % 2 == 1)answer = "1" + answer;
        else answer = "0" + answer;
        t1 /= 2;
    }
    return answer;
}

int main() {
    cout << solution("10", "11");
}