#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  int whr1[n + 1], whr2[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    whr1[a[i]] = i;
  }

  int here = -1;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    whr2[b[i]] = i;
    if (n & 1) {
      if (a[i] == b[i]) here = i;
    }
  }

  vector<pair<int, int>> ans;
  int x = (n / 2) + 1;
  if ((n & 1) and x != here and here != -1) {
    ans.push_back({x, here});
    swap(whr1[a[x]], whr1[a[here]]);
    swap(whr2[b[x]], whr2[b[here]]);
    swap(a[x], a[here]);
    swap(b[x], b[here]);
  }

  for (int i = n, j = 1; i >= x; i--, j++) {
    if (a[i] == b[j]) continue;
    int idx = whr2[a[i]];
    ans.push_back({j, idx});
    swap(whr1[a[j]], whr1[a[idx]]);
    swap(whr2[b[j]], whr2[b[idx]]);
    swap(a[j], a[idx]);
    swap(b[j], b[idx]);
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << a[i] << ' ';
  // }
  // cout << '\n';
  // for (int i = 1; i <= n; i++) {
  //   cout << b[i] << ' ';
  // }
  // cout << '\n';

  assert(ans.size() <= n);
  for (int i = n, j = 1; i >= 1; i--, j++) {
    if (a[i] != b[j]) {
      cout << -1 << '\n';
      return;
    }
  }

  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    if (x > y) swap(x, y);
    cout << x << ' ' << y << '\n';
  }
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