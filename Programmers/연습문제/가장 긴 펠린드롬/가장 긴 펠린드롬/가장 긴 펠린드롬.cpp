//프로그래머스 가장 긴 팰린드롬
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int palindrome(string& s, int left, int right) {
    while (left >= 0 && right < s.size()) { //이동할 수 없을때까지
        if (s[left] != s[right])
            break;
        left--; //왼쪽으로 이동
        right++; //오른쪽으로 이동
    }
    return right - left - 1; // 거리
}


int solution(string s) {
    int answer = 1;

    for (int i = 1; i < s.size(); i++) {
        int left = i - 1;
        int right = i + 1;
        int odd = palindrome(s, left, right);
        int even = palindrome(s, left, right - 1);
        answer = max({ answer, odd, even }); //최대값 구하기
    }
    return answer;
}

int main() {
    string s = "ABCCBA";
    cout << solution(s) << "\n";
    return 0;
}