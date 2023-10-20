#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq; 
    priority_queue<int, vector<int>,greater<int>>pq2;

    for (auto i : A)pq.push(i);
    for (auto i : B)pq2.push(i);
    
    while (!pq.empty() && !pq2.empty()) {
        if (pq.top() < pq2.top()) {
            answer++;
            pq.pop();
        }
        pq2.pop();
    }
   
    return answer;
}

int main() {
    cout << solution({ 5,1,3,7 }, { 2,2,6,8 });
}