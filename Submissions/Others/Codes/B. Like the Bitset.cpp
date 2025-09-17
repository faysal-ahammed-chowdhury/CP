#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;

  int cnt = 0;
  set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(i);
    if (s[i] == '1') {
      cnt++;
    }
    else {
      if (cnt >= k) {
        cout << "NO\n";
        return;
      }
      cnt = 0;
    }
  }

  if (cnt >= k) {
    cout << "NO\n";
    return;
  }

  int ans[n + 1];
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      ans[i] = *se.begin();
      se.erase(se.begin());
    }
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      ans[i] = *se.begin();
      se.erase(se.begin());
    }
    cout << ans[i] << ' ';
  }
  cout << '\n';
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