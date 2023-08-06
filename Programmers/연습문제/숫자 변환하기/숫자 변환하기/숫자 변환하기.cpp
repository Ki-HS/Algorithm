#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;
//     int answer = 0;

// void dfs(int x, int y, int n, int time){
//     if(x>y){
//         answer= (answer==0)? -1: answer;
//         return;
//     }
//     else if (x == y ){
//         answer = (answer == -1 ||answer == 0 || answer > time) ? time : answer;
//         return;
//     }

//     dfs(x+n, y, n, time+1);
//     dfs(x*2, y, n, time+1);
//     dfs(x*3, y, n, time+1);
// }

//int solution(int x, int y, int n) {
//    //dfs(x,y,n,0);
//
//    int answer = 0;
//    queue<int> q;
//    q.push(x + n);
//    q.push(x * 2);
//    q.push(x * 3);
//    int imp = 2;
//    while (!q.empty()) {
//        int t = q.front();
//        q.pop();
//        if (t == y) {
//            answer++; break;
//        }
//        if (t > y)continue;
//        q.push(t + n);
//        q.push(t * 2);
//        q.push(t * 3);
//        if (q.size() == pow(3, imp)) {
//            imp++;
//            answer++;
//        }
//    }
//    if (answer == 0)answer = -1;
//    return answer;
//}

#define MAX 9999999

//map으로 하면 더 느림
//map<int, int> m;
int m[1000001] = { 0, };

int dfs(int x, int y, int n, int time) {
    if (m[x] != 0 && m[x] <= time)return MAX;
    m[x] = time;
    if (x == y)return time;
    int a, b, c;
    a = b = c = MAX;
    if (x + n <= y)
        a = dfs(x + n, y, n, time + 1);
    if (x * 2 <= y)
        b = dfs(x * 2, y, n, time + 1);
    if (x * 3 <= y)
        c = dfs(x * 3, y, n, time + 1);

    return min(a, min(b, c));
}

int solution(int x, int y, int n) {
    int answer = dfs(x, y, n, 0);
    if (answer >= MAX) {
        answer = -1;
    }
    return answer;
}
int main() {
    cout << solution(10, 40, 5);
}