#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
int n, l, r, a[N], pref[N], dp[N];

int f(int i) {
  if (i > n) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = 0;
  if (a[i] >= l and a[i] <= r) {
    ans = max(ans, 1 + f(i + 1));
  }
  else {
    ans = max(ans, f(i + 1));
    int low = pref[i - 1] + l;
    int idx = lower_bound(pref + 1, pref + n + 1, low) - pref;
    if (idx != n + 1) {
      int val = pref[idx] - pref[i - 1];
      if (val >= l and val <= r) {
        ans = max(ans, 1 + f(idx + 1));
      }
    }
  }
  return ans;
}

void solve() {
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }
  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
  }
  cout << f(1) << '\n';
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