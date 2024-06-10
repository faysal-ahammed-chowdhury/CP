#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  map<char, int> mp;
  for (auto c : s) {
    mp[c]++;
  }
  if (mp.size() == 1) {
    cout << -1 << '\n';
  }
  else {
    string out = "";
    for (auto [c, cnt] : mp) {
      for (int i = 1; i <= cnt; i++) {
        out += c;
      }
    }
    cout << out << '\n';
  }
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