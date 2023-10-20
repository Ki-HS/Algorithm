#include <string>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());
    ll min = times[0];
    ll max = (ll)n * (ll)times.back();
    ll ans = 0;
    while (min <= max) {
        ll mid = (min + max) / 2;
        ll p = 0;
        for (auto time : times) {
            p += mid / time;

        }
        if (p < n) {
            min = mid + 1;
        }
        else {
            ans = mid;
            max = mid - 1;
        }

    }


    return ans;
}