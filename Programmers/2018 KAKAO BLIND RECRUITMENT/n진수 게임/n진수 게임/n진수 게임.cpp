#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<stack>
using namespace std;

vector<char> number = { '0','1','2','3','4','5','6','7',
                    '8','9','A','B','C','D','E','F' };

//n : 진법
//t : 미리 구할 숫자의 갯수
//m : 참가하는 인원
//p : 순서
string solution(int n, int t, int m, int p) {
    string answer = "";

    queue<char> temp;
    int num = 0;
    while (t) {
        int tmp = num;
        int seq = p;
        while (temp.size() < m) {
            if (tmp == 0)temp.push('0');
            stack<char> st;
            while (tmp) {
                st.push(number[tmp % n]);
                tmp /= n;
            }
            while (!st.empty()) {
                temp.push(st.top());
                st.pop();
            }
            num++;
            tmp = num;
        }
        for (int i = 0; i < m; i++) {
            if (i + 1 == seq)answer += temp.front();
            temp.pop();
        }
        t--;
    }

    return answer;
}

int main() {
    solution(2, 4, 2, 1);
}