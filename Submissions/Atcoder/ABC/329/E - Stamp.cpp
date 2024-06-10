#include <bits/stdc++.h>
using namespace std;

map<char, set<char>> g;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  string s, t; cin >> s >> t;

  if (s.front() != t.front()) {
    cout << "No\n";
    return 0;
  }

  for (int i = 0; i + 1 < m; i++) {
    g[t[i]].insert(t[i + 1]);
  }
  for (int i = 0; i < m; i++) {
    g[t.back()].insert(t[i]);
    g[t[i]].insert(t.front());
  }

  char cur = t.front();
  for (int i = 1; i < n; i++) {
    if (g[cur].find(s[i]) == g[cur].end()) {
      cout << "No\n";
      return 0;
    }
    else {
      cur = s[i];
    }
  }

  if (cur == t.back()) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }

  return 0;
}