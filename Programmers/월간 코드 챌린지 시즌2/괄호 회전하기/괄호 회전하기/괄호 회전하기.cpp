#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        stack<char> st;
        bool flag = true;
        for (int j = 0; j < s.size(); j++) {
            if (s[(i + j) % s.size()] == '(' || s[(i + j) % s.size()] == '[' || s[(i + j) % s.size()] == '{') {
                st.push(s[(i + j) % s.size()]);
            }
            else if (s[(i + j) % s.size()] == ')') {
                if (st.top() == '(') st.pop();
                else { flag = false; break; }
            }
            else if (s[(i + j) % s.size()] == ']') {
                if (st.top() == '[') st.pop();
                else { flag = false; break; }
            }
            else if (s[(i + j) % s.size()] == '}') {
                if (st.top() == '{') st.pop();
                else { flag = false; break; }
            }
        }
        if (st.empty() && flag) {
            answer++;
        }
    }
    return answer;
}