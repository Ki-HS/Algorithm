#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);

        string case1 = s1 + s2;
        string case2 = s2 + s1;
        return case1 < case2;
        // if(s1[0]==s2[0]){
        //     if(s1.size()==s2.size())
        //         return s1<s2;
        //     if(s1.size()<s2.size()){
        //         bool flag = false;
        //         for(int i =0 ; i< s1.size(); i++){
        //             if(s1[i]>s2[i+1]) break;
        //             else if (s1[i]<s2[i+1]){
        //                 flag = true;
        //                 break;
        //             }
        //         }
        //         return flag;
        //     }
        //     return s1.size()>s2.size();
        // }
        // return s1[0]<s2[0];
    }
};

string solution(vector<int> numbers) {
    string answer = "";

    priority_queue<int, vector<int>, cmp> pq;
    for (int i : numbers)pq.push(i);

    while (!pq.empty()) {
        if (answer == "" && pq.top() == 0) {
            pq.pop();
            continue;
        }
        answer += to_string(pq.top());
        pq.pop();
    }
    if (answer == "") answer = "0";

    return answer;
}