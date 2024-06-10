#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 105;
int n, w, k, a[N], dp[N][K];

int fun(int i, int rem) {
  if (i == n + 1 or rem == 0) {
    return 0;
  }
  int &ans = dp[i][rem];
  if (ans != -1) return ans;
  int now = a[i];
  int mx = now + w;
  auto it = upper_bound(a + 1, a + n + 1, mx);
  int go = it - &(a[1]) + 1;
  int paisi = it - &(a[i]);
  ans = max(paisi + fun(go, rem - 1), fun(i + 1, rem));
  return ans;
}

int cs;
void solve() {
  cin >> n >> w >> k;
  for (int i = 1; i <= n; i++) {
    int tmp; cin >> tmp >> a[i];
  }
  sort(a + 1, a + n + 1);
  memset(dp, -1, sizeof(dp));
  cout << "Case " << ++cs << ": ";
  cout << fun(1, k) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}