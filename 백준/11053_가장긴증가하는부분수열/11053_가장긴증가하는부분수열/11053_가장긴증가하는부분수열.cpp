#include <iostream>
#include <algorithm>
using namespace std;
int main() 
{
  int arr[1001] = {0,};
  int dp[1001] = {0,};

  int N;
  cin >> N;
  
  for(int i = 1; i<=N; i++)
    {
      cin >> arr[i];
    }
  dp[1] = 1;
  
  int result = dp[1];
  for(int i = 2; i<=N; i++)
    {
      for(int j = i-1; j>=0; j--)
        {
          if(arr[i] > arr[j])
          {
             dp[i] = max(dp[i], dp[j]+1);
          }
        }
      result = max(dp[i], result);
    }
  cout << result;
}