#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<int, int> l, r;
    l = make_pair(3, 0);
    r = make_pair(3, 2);

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            l.first = (numbers[i] - 1) / 3;
            l.second = (numbers[i]-1) % 3;
            answer += 'L';
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            r.first = (numbers[i] - 1) / 3;
            r.second = (numbers[i] - 1) % 3;
            answer += 'R';
        }
        else {
            int mx = (numbers[i] - 1) / 3;
            int my = (numbers[i] - 1) % 3;
            if (numbers[i] == 0) {
                mx = 3; my = 1;
            }
            if (abs(mx - l.first) + abs(my - l.second) < abs(mx - r.first) + abs(my - r.second)) {
                l.first = (numbers[i] - 1) / 3;
                l.second = (numbers[i] - 1) % 3;
                if (numbers[i] == 0) {
                    l.first = 3;
                    l.second = 1;
                }
                answer += 'L';
            }
            else if (abs(mx - l.first) + abs(my - l.second) > abs(mx - r.first) + abs(my - r.second)) {
                r.first = (numbers[i] - 1) / 3;
                r.second = (numbers[i] -1) % 3;
                if (numbers[i] == 0) {
                    r.first = 3;
                    r.second = 1;
                }
                answer += 'R';
            }
            else {
                if (hand == "right") {
                    r.first = (numbers[i] - 1) / 3;
                    r.second = (numbers[i]-1) % 3;
                    if (numbers[i] == 0) {
                        r.first = 3;
                        r.second = 1;
                    }
                    answer += 'R';
                }
                else {
                    l.first = (numbers[i] - 1) / 3;
                    l.second = (numbers[i]-1) % 3;
                    if (numbers[i] == 0) {
                        l.first = 3;
                        l.second = 1;
                    }
                    answer += 'L';
                }
            }
        }
    }


    return answer;
}

int main() {
    vector<int> numbers = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand = "left";
    
    cout << solution(numbers, hand);
}