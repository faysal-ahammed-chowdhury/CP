#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 9, K = 105;
int dp[N];
int k, p[K];

int f(int n) {
  int &ans = dp[n];
  if (ans != -1) return ans;
  bool mex[k + 5];
  memset(mex, 0, sizeof mex);
  for (int i = 1; i <= k; i++) {
    if (n - p[i] >= 0) {
      mex[f(n - p[i])] = 1;
    }
  }
  for (int i = 0; i <= k + 2; i++) {
    if (mex[i] == 0) {
      ans = i;
      break;
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  memset(dp, -1, sizeof dp);
  // cout << f(1) << '\n';

  for (int i = 1; i <= n; i++) {
    if (f(i)) cout << "W";
    else cout << "L";
  }
  cout << '\n';

  return 0;
}