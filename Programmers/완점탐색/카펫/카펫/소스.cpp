#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    int yellowWidth = yellow, yellowHeight = 1;
    while (sum != (yellowWidth + 2) * (yellowHeight + 2)) {
        yellowHeight++;
        if (yellow % yellowHeight)continue;
        yellowWidth = yellow / yellowHeight;
    }
    return { yellowWidth + 2, yellowHeight + 2 };
    return answer;
}