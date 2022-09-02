#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int, int>m;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            m[numbers[i] + numbers[j]]++;
        }
    }

    for (auto i : m) {
        answer.push_back(i.first);
    }
    return answer;
}