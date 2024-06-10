#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 9;
ll dp[N][5];
int arr[N][5];

ll fun(int pos, int activity) {
  if(pos == 0) {
    return 0;
  }
  if(dp[pos][activity] != -1) {
    return dp[pos][activity];
  }
  ll ans1, ans2;
  if(activity == 1) {
    ans1 = arr[pos][activity] + fun(pos - 1, 2);
    ans2 = arr[pos][activity] + fun(pos - 1, 3);
  }
  else if(activity == 2) {
    ans1 = arr[pos][activity] + fun(pos - 1, 1);
    ans2 = arr[pos][activity] + fun(pos - 1, 3);
  }
  else {
    ans1 = arr[pos][activity] + fun(pos - 1, 1);
    ans2 = arr[pos][activity] + fun(pos - 1, 2);
  }
  ll ans = max(ans1, ans2);
  dp[pos][activity] = ans;
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
  }

  ll ans1 = fun(n, 1);
  ll ans2 = fun(n, 2);
  ll ans3 = fun(n, 3);

  cout << max({ans1, ans2, ans3}) << '\n';

  return 0;
}