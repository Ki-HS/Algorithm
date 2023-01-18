#include <string>
#include <vector>

using namespace std;

string solution(string my, int num1, int num2) {
    string answer = my;
    answer[num1] = my[num2];
    answer[num2] = my[num1];
    return answer;
}