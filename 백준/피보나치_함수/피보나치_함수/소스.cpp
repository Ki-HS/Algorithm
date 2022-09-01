#include <iostream>
#include <vector>
using namespace std;
int one = 0;
int zero = 0;
vector<pair<int, int>> oz;

int main() {
    int n;
    cin >> n;
    int t;
    vector<int> q;
    int fibo[41] = { 0,1,1 };
    for (int i = 3; i < 41; i++)fibo[i] = fibo[i - 1] + fibo[i - 2];
    while (n--) {
        cin >> t;
        q.push_back(t);
    }

    for (int i = 0; i < q.size(); i++) {
        if (q[i] == 0)cout << 1 << " " << 0 << "\n";
        else if (q[i] == 1) cout << 0 << " " << 1 << "\n";
        else 
        cout << fibo[q[i]-1] << " " << fibo[q[i]] << "\n";
    }
}