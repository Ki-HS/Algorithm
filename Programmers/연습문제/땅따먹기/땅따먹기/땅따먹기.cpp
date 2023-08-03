#include <iostream>
#include <vector>
using namespace std;

//첫 번째 풀이
//int answer=0;
// void dfs(vector<vector<int>> l, int depth, int cur, int sum){
//     if(depth==l.size()){
//         answer=(answer>sum)?answer:sum;
//         return;
//     }
//     for(int i=0; i<l[0].size(); i++){
//         if(i!=cur)
//             dfs(l,depth+1,i,sum+l[depth][i]);
//     }
// }

// int solution(vector<vector<int> > land)
// {
//     for(int i = 0; i<land[0].size(); i++)
//         dfs(land, 0, i, 0);

//     return answer;
// }

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int max = 0;
            for (int k = 0; k < 4; k++) {
                if (j != k)max = (max < land[i - 1][k]) ? land[i - 1][k] : max;
            }
            land[i][j] += max;
        }
    }

    for (int i = 0; i < 4; i++) {
        answer = (answer > land.back()[i]) ? answer : land.back()[i];
    }

    return answer;
}