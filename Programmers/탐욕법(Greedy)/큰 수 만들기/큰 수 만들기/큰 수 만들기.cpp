#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string answer = "";

string solution(string number, int k) {
    
    char maxInt = '0';
    int maxIdx = 0;
    int cur = 0; 
    while (k > 0&&answer.size()<number.size()-k) {
        char max = 0; 
        for (int i = cur; i < cur + k + 1&&i<number.size(); i++) {
            if (max < number[i]) {
                maxIdx = i;
                max = number[i];
            }
        }
        k -= maxIdx-cur;
        answer += number[maxIdx];
        cur = maxIdx + 1;
    }

    if (answer.size() < number.size() - k) {
        for (int i = cur; i < number.size(); i++) answer += number[i];
    }

    /*for (int i = 0; i < k; i++) {
        if (maxInt <number[i]) {
            maxIdx = i;
            maxInt = number[i];
        }        
    }
    k -= maxIdx;

    int cur = maxIdx;
    for (int i = 1; i <= k; i++) {
        maxInt = number[i+cur];
        maxIdx = cur + i;

        
        
    }*/


    return answer;
}

int main() {
    cout<<solution("9929191", 5);
}