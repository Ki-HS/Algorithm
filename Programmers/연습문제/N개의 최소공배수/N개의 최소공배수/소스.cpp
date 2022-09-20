#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)return a;
    return gcd(b, a % b);
}

int solution(vector<int> arr) {
    int answer = 1;
    for (int i = 0; i < arr.size(); i++) {
        answer = (answer * arr[i]) / gcd(answer, arr[i]);
    }
    return answer;
}