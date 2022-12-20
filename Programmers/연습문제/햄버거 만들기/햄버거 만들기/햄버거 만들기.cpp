#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> ing) {
    int answer = 0;
    vector<int> temp;

    for (int i = 0; i < ing.size(); i++) {
        temp.push_back(ing[i]);
        bool s = true;
        if (1 == temp.back() && temp.size() > 3) {
            int t = 3;
            for (int j = temp.size() - 2; j >= 0; j--) {
                if (temp[j] != t) {
                    s = false;
                    break;
                }
                if (t == 1) break;
                t--;
            }
            if (s) {
                t = 4;
                while (t--) {
                    temp.pop_back();
                }
                answer++;
            }
        }
    }


    return answer;
}

int main() {
    vector<int> ing = { 1,1,2,3,1,2,3,1 };
    cout << solution(ing);
}