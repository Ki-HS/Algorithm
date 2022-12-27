#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    vector<int> v;
    for (int i = 1; i < food.size(); i++) {
        v.push_back(food[i] / 2);
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i]; j++) {
            answer += '0' + i + 1;
        }
    }
    answer += '0';
    for (int i = v.size() - 1; i >= 0; i--) {
        for (int j = 0; j < v[i]; j++) {
            answer += '0' + i + 1;
        }
    }
    return answer;
}