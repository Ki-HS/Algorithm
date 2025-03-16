#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    //짝수 왼쪽, 홀수 오른쪽
    //층수 n/w
    
    int floor = n/w;
    
    int target_y = num%w;
    int target_x = target_y==0 ? num/w-1:num/w;
    int direct = target_x%2;

    answer += floor - target_x;
    int start = 0;
    if(floor%2){
        start = w-n%w;
    }
    
    if(direct){
        target_y = w-target_y;
    }

    if(target_y>=start &&target_y<=start+n%w&&w!=1)
        answer++;
    
    return answer;
}

int main(){
    solution(100,9,45);
}