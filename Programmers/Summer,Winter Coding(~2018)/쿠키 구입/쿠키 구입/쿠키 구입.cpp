#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> cookie) {
    int answer = -1;
    //1Ʈ
//     for(int i=0;i<cookie.size()-1; i++){
//         stack<int> s;
//         s.push(cookie[i]);
//         for(int j = i-1; j>=0; j--){
//             s.push(s.top()+cookie[j]);
//         }

//         while(!s.empty()){
//             int std = s.top(); 
//             int cur = i+1;
//             int sum = 0;
//             while(cur!=cookie.size()&&sum<std){
//                 sum+=cookie[cur];
//                 cur++;
//             }

//             if(sum==std) answer= answer>std?answer:std;
//             s.pop();
//         }
//     }

    //2Ʈ
//     vector<int> left(2000,cookie.size());
//     vector<int> right(2000,cookie.size());
//     int sum=0;
//     for(int i = 0 ; i < cookie.size(); i++){
//         sum+=cookie[i];
//         left[i]=sum;
//     }

//     for(int i = 0 ; i < cookie.size(); i++){
//         right[i]=sum;
//         sum-=cookie[i];
//     }

//     for(int i =0; i<cookie.size()-1; i++){
//         for(int j =0; j<=i; j++){
//             for(int k=cookie.size()-1; k>=i+1; k--){
//                 int big_bro = (i==j)? left[i] : left[i]-left[j];
//                 int small_bro = (i+1==k)? right[k]: right[i+1]-right[k];
//                 if(big_bro<small_bro)continue;
//                 if(big_bro==small_bro) answer=answer>big_bro?answer:big_bro;
//             }
//         }
//     }

    //3Ʈ
    for (int i = 0; i < cookie.size() - 1; i++) {
        int big = cookie[i];
        int small = cookie[i + 1];
        int big_cur = i;
        int small_cur = i + 1;

        while (big_cur || small_cur != cookie.size()) {
            if (!big_cur && big < small)break;
            if (small_cur == cookie.size() - 1 && big > small)break;

            if (big == small)answer = answer > big ? answer : big;

            if (big > small) {
                small_cur++; small += cookie[small_cur];
            }
            else if (big < small) {
                big_cur--;
                big += cookie[big_cur];
            }
            else {
                if (big_cur) { big_cur--; big += cookie[big_cur]; }
                else { small_cur++; small += cookie[small_cur]; }
            }
        }


    }



    if (answer == -1)return 0;
    return answer;
}