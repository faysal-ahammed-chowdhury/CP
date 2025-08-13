#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2500 + 9, mod = 998244353;
int n, k, dp[N][N];

int f(int last, int cnt) {
  if (cnt == n) return 1;
  int &ans = dp[last][cnt];
  if (~ans) return ans;
  ans = 0;
  for (int i = 1; i <= k; i++) {
    if (last + i - 1 > k) break;
    if (cnt + (last * i) <= n) {
      ans += f(i, cnt + (last * i));
      ans %= mod;
    }
    else break;
  }
  return ans;
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = -1;
    }
  }
  cout << f(0, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}