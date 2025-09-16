#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  set<int, greater<int>> se;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] != 0) {
      se.erase(a[i]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      a[i] = *se.begin();
      se.erase(se.begin());
    }
  }

  int ok1 = 0, ok2 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == i) continue;
    ok1 = i - 1;
    break;
  }

  for (int i = n; i >= 1; i--) {
    if (a[i] == i) continue;
    ok2 = i + 1;
    break;
  }

  int ans = ok2 - ok1 - 1;
  ans = max(0, ans);
  cout << ans << '\n';
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