#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    while (x % 2 == 0) {
      cnt++;
      x /= 2;
    }
  }

  if (cnt >= n) {
    cout << 0 << '\n';
    return;
  }

  int need = n - cnt;
  cnt = 0;
  vector<int> v;
  for (int i = n; i >= 1; i--) {
    int x = i, found = 0;
    while (x % 2 == 0) {
      found++;
      x /= 2;
    }
    cnt += found;
    v.push_back(found);
  }

  if (cnt >= need) {
    sort(v.rbegin(), v.rend());
    cnt = 0;
    int ans = 0;
    while (cnt < need) {
      cnt += v[ans];
      ans++;
    }
    cout << ans << '\n';
  }
  else {
    cout << -1 << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}