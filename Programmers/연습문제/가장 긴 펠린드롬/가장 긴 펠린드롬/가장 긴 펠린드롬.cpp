//���α׷��ӽ� ���� �� �Ӹ����
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int palindrome(string& s, int left, int right) {
    while (left >= 0 && right < s.size()) { //�̵��� �� ����������
        if (s[left] != s[right])
            break;
        left--; //�������� �̵�
        right++; //���������� �̵�
    }
    return right - left - 1; // �Ÿ�
}


int solution(string s) {
    int answer = 1;

    for (int i = 1; i < s.size(); i++) {
        int left = i - 1;
        int right = i + 1;
        int odd = palindrome(s, left, right);
        int even = palindrome(s, left, right - 1);
        answer = max({ answer, odd, even }); //�ִ밪 ���ϱ�
    }
    return answer;
}

int main() {
    string s = "ABCCBA";
    cout << solution(s) << "\n";
    return 0;
}