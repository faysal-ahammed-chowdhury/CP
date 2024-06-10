#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 509;
long long dp[N][N];
int a, b; 

int solution(int x, int y) {
  if(x == a && y == b) {
    return 1;
  }
  if(x > a || y > b) {
    return 0;
  }
  if(dp[x][y] != -1) {
    return dp[x][y];
  }
  long long ans1 = solution(x + 2, y) % mod;
  long long ans2 = solution(x + 3, y) % mod;
  long long ans3 = solution(x, y + 2) % mod;
  long long ans4 = solution(x, y + 3) % mod;
  long long ans = (ans1 + ans2 + ans3 + ans4) % mod;
  dp[x][y] = ans;
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      dp[i][j] = -1;
    }
  }

  cin >> a >> b;
  long long ans = solution(0, 0);
  cout << ans << '\n';
        
  return 0;
}