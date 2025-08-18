#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  n += n;

  set<int> lvl[n + 1];

  stack<pair<int, int>> st;
  st.push({0, 0});
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(') {
      int x = st.top().second;
      st.push({x + 1, i});
    }
    else {
      auto [x, _] = st.top();
      st.pop();
      lvl[x].insert(st.top().second);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += lvl[i].size();
    // cout << i << ' ' << lvl[i].size() << '\n';
  }
  cout << ans << '\n';
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