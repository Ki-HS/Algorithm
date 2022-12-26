#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool status(vector<int>d, vector<int>p) {
    for (int i = 0; i < d.size(); i++) {
        if (d[i] || p[i])return true;
    }
    return false;
}

//long long solution(int cap, int n, vector<int> d, vector<int> p) {
//    long long answer = 0;
//    long box;
//    long dbox, pbox;
//    int idx = n;
//    while (status(d, p)) {
//        idx = n-1;
//        dbox = pbox = 0;
//        int temp = cap;
//        //박스 실음
//        for (int i = n - 1; i >= 0; i--) {
//            if (pbox != cap) {
//                dbox += d[i];
//                pbox += p[i];
//                if (dbox > cap)dbox = cap;
//                if (pbox > cap)pbox = cap;
//            }
//            else break;
//        }
//        pbox = 0;
//        //배달
//            answer += n*2;
//        while (idx>-1&&pbox != cap) {
//            if (dbox > d[idx]) { dbox -= d[idx]; d[idx] = 0; }
//            else { d[idx] -= dbox; dbox = 0; }
//            if (cap - pbox - dbox > p[idx]) { pbox += p[idx]; p[idx] = 0; }
//            else { p[idx] -= cap - pbox - dbox; pbox += cap - pbox - dbox; }
//
//            if (p[idx] == 0 && d[idx] == 0) {
//                n--;
//            }
//            else idx--;
//        }
//
//    }
//
//    return answer;
//}

long long solution(int cap, int n, vector<int> d, vector<int> p) {
    long long ans = 0;
    long long box = 0;
    bool status = false;
    while(n) {
        box = 0;
        status = false;
        ans += n * 2;
        while (n&&box!=cap&&!status) {
            if (d[n - 1]) {
                if (cap > box+d[n - 1])d[n - 1] = 0;
                else {
                    d[n - 1] -= cap;
                    status = true;
                }
            }
            if (box+d[n - 2] + p[n - 1] > cap) {
                if (p[n - 1] > cap) {
                    p[n - 1] -= cap;
                    box += cap;
                    status = true;
                }
                else {
                    box += p[n - 1];
                    d[n - 2] -= cap - p[n - 1];
                    p[n - 1] = 0;
                }
            }
            n--;
        }
    }

    return ans;
}

int main() {
    vector<int> a = { 1,0,3,1,2 };
    vector<int>b = { 0,3,0,4,0 };
    cout << solution(4, 5, a, b);
}