#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }

  set<int> se;
  for (auto [x, cnt] : mp) {
    if (cnt == 1) se.insert(x);
  }

  int b[n + 1];
  memset(b, 0, sizeof b);
  for (int i = 1; i <= n; i++) {
    if (se.find(a[i]) != se.end()) {
      b[i] = 1;
    }
  }

  int cnt = 0, ans = 0;
  int l = -1, r = -1;
  for (int i = 1; i <= n; i++) {
    if (b[i] == 1) cnt++;
    else {
      if (cnt > ans) {
        r = i - 1;
        l = r - cnt + 1;
        ans = cnt;
      }
      cnt = 0;
    }
  }
  if (cnt > ans) {
    r = n;
    l = r - cnt + 1;
    ans = cnt;
  }
  if (ans == 0) {
    cout << ans << '\n';
    return;
  }
  cout << l << ' ' << r << '\n';
  assert(l <= r);
  assert(l > 0 and r > 0);
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