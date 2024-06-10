#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 3e5 + 9;
int n;
pair<int, int> a[N];
long long dp[N][2];

long long solution(int pos, int heath_state) {
  if(pos == 0) {
    return 0;
  }
  if(dp[pos][heath_state] != -1) {
    return dp[pos][heath_state];
  }
  long long ans1 = 0, ans2 = 0, ans3 = 0;
  if(a[pos].first == 0) {
    ans1 = a[pos].second + solution(pos - 1, 0);
  }
  else if(heath_state == 0) {
    ans2 = a[pos].second + solution(pos - 1, 1);
  }
  ans3 = solution(pos - 1, heath_state);
  long long ans = max({ans1, ans2, ans3});
  dp[pos][heath_state] = ans;
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
    dp[i][0] = -1;
    dp[i][1] = -1;
  }
  
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    a[i] = {x, y};
  }
  cout << solution(n, 0) << '\n';

  return 0;
}