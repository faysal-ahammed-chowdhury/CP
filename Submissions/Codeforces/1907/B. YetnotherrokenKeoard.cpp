#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  stack<pair<char, int>> up, lo;
  set<int> se;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    se.insert(i);
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == 'b') {
      if (!lo.empty()) {
        auto last = lo.top();
        lo.pop();
        se.erase(last.second);
      }
      se.erase(i);
    }
    else if (s[i] == 'B') {
      if (!up.empty()) {
        auto last = up.top();
        up.pop();
        se.erase(last.second);
      }
      se.erase(i);
    }
    else {
      if (s[i] >= 'A' and s[i] <= 'Z') {
        up.push({s[i], i});
      }
      else {
        lo.push({s[i], i});
      }
    }
  }

  for (auto x : se) {
    cout << s[x];
  }
  cout << '\n';
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