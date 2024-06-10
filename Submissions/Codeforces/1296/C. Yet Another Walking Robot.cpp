#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  pair<int, int> cur = {0, 0};
  int ans = n + 5;
  map<pair<int, int>, int> mp;
  int st = -1, end = -1;
  for (int i = 1; i <= n + 1; i++) {
    if (mp.find(cur) != mp.end()) {
      if (i - mp[cur] < ans) {
        st = mp[cur], end = i - 1;
      }
      ans = min(ans, i - mp[cur]);
    }
    if (i == n + 1) break;
    mp[cur] = i;
    if (s[i] == 'L') cur.first--;
    if (s[i] == 'R') cur.first++;
    if (s[i] == 'U') cur.second++;
    if (s[i] == 'D') cur.second--;
  }
  if (st == -1) cout << -1 << '\n';
  else cout << st << ' ' << end << '\n';
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