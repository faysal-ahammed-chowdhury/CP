#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '@' + s;
  set<int> se;
  int ans[n + 1];
  int last_b = -1;
  for (int i = 1; i <= n; i++) {
    se.insert(i);
    if (s[i] == 'B') {
      int x = *se.begin();
      se.erase(se.begin());
      ans[i] = x;
      last_b = i;
    }
    if (s[i] == 'B' and s[i - 1] == 'B') {
      cout << -1 << '\n';
      return;
    }
  }

  if (last_b == -1) {
    cout << -1 << '\n';
    return;
  }

  for (int i = 1; i <= last_b; i++) {
    if (s[i] == 'A') {
      auto it = se.end();
      --it;
      int x = *it;
      se.erase(x);
      ans[i] = x;
    }
  }

  for (int i = last_b + 1; i <= n; i++) {
    int x = *se.begin();
    se.erase(se.begin());
    ans[i] = x;
    last_b = i;
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
  while (t--) {
    solve();
  }

  return 0;
}