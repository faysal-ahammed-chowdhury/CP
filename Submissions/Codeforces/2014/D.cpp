#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, d, k; cin >> n >> d >> k;
  int diff[n + 1];
  memset(diff, 0, sizeof diff);
  while (k--) {
    int l, r; cin >> l >> r;
    l = max(1ll, l - d + 1);
    r = min(r, n - d + 1);
    // cout << l << ' ' << r << '\n';
    diff[l]++;
    if (r + 1 <= n) {
      diff[r + 1]--;
    }
  }
  for (int i = 1; i <= n; i++) {
    diff[i] += diff[i - 1];
    // cout << diff[i] << ' ';
  }
  int end = n - d + 1;
  int idx1 = -1, idx2 = -1, mn = 1e9, mx = -1e9;
  for (int i = 1; i <= end; i++) {
    if (diff[i] < mn) {
      mn = diff[i];
      idx2 = i;
    }
    if (diff[i] > mx) {
      mx = diff[i];
      idx1 = i;
    }
  }
  cout << idx1 << ' ' << idx2 << '\n';
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