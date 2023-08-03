#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> proc1(vector<int> seq, vector<int> cur, int start, int end, int k) {
    if (start == seq.size())return cur;
    if (end == seq.size())return proc1(seq, cur, start + 1, start + 1, k);

    int sum = 0;
    for (int i = start; i <= end; i++)sum += seq[i];
    if (sum == k) {
        if (end - start < cur[1] - cur[0]) {
            cur[1] = end;
            cur[0] = start;
        }

        return cur;
    }
    if(sum>k) return proc1(seq, cur, start + 1, start + 1, k);

    return proc1(seq, cur, start, end + 1, k);
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int size = sequence.size();
    answer = proc1(sequence, { 0,size - 1 }, 0, 0, k);
    return answer;
}

int main() {
    solution({ 1,1,1,2,3,4,5 }, 5);
}