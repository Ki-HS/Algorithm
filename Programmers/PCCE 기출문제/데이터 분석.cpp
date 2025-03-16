#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sort_idx =0;

int get_idx(string str){
    int idx;
    
    if(str== "code")
            idx = 0;
    else if(str == "date")
            idx =1;
    else if(str == "maximum")
            idx=2;
    else    idx= 3;

    return idx;
}

bool compare(vector<int> a, vector<int> b){
    return a[sort_idx]< b[sort_idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int extract_idx = get_idx(ext);
     sort_idx = get_idx(sort_by);
    
    for(auto d : data){
        if(d[extract_idx]<val_ext)
            answer.emplace_back(d);
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}