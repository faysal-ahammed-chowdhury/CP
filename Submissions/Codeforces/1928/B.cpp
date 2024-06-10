#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int x = n;
  int a[n + 1];
  set<int> se;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se.insert(a[i]);
  }

  n = se.size();
  int idx = 1;
  for (auto x : se) {
    a[idx++] = x;
  }

  int l = 1, r = 1;
  int ans = 1;
  while (l <= n and r <= n) {
    while (l <= r and r <= n) {
      if (a[r] - a[l] > x - 1) {
        l++;
        break;
      }
      else {
        ans = max(ans, r - l + 1);
        r++;
      }
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}