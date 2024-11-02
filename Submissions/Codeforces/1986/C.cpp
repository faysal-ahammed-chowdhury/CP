#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  string s; cin >> s;
  set<int> se;
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    se.insert(x);
  }
  string t; cin >> t;
  sort(t.begin(), t.end());
  int id = 0;
  for (auto x : se) {
    s[x - 1] = t[id++];
  }
  cout << s << '\n';
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