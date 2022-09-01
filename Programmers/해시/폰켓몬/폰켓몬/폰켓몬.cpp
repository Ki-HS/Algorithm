#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int, int> m;
    for (auto i : nums) {
        m[i]++;
    }
    if (m.size() > nums.size() / 2) { return nums.size() / 2; }
    else return m.size();
}