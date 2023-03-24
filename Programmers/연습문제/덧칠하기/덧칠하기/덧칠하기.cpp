#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    for (int i = 0; i < section.size(); i++) {
        int t = section[i];
        int j = i + 1;
        int c = 0;
        for (; j < section.size(); j++) {
            if (section[j] < t + m)c++;
            else break;
        }
        i += c;
        answer++;
    }
    return answer;
}