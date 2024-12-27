#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  set<int, greater<>> se;
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    se.insert(x);
  }

  set<int> a[n + 1];
  int ans[n + 1];
  ans[1] = *se.begin();
  se.erase(se.begin());
  for (int i = 2; i <= n; i++) {
    int here = -1;
    for (auto x : se) {
      if (a[i].find(x) == a[i].end()) {
        here = x;
        break;
      }
    }
    ans[i] = here;
    if (here == -1) {
      cout << -1 << '\n';
      return;
    }
    for (int j = i + i; j <= n; j += i) {
      a[j].insert(here);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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