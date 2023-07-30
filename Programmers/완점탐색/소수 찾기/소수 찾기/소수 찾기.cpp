#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

vector<bool> vis(7, false);//방문 배열
map<int, int>m;
int answer = 0,n;
void dfs(string cur, string numbers)
{
    if (cur.size() > 0 && m[stoi(cur)]==0)
    {
        int tmp = stoi(cur);
        bool flag = false;
        if (tmp != 1 && tmp != 0) {
            for (int i = 2; i < sqrt(tmp); i++) {
                if (tmp % i == 0) {
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                m[stoi(cur)]++;
                answer++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            string tmp = cur + numbers[i];//기존 숫자열 + 아직 안쓴 숫자
            vis[i] = true;
            dfs(tmp, numbers);
            vis[i] = false;
        }
    }
}

int solution(string numbers) {

    n = numbers.size();
    dfs("", numbers);

    return answer;
}

int main() {
    cout << solution("17");
}