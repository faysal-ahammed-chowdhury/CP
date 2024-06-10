#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  map<char, int> mp;
  for (auto c : s) mp[c]++;
  vector<char> dupli;
  string ans = "";
  for (auto [c, cnt] : mp) {
    if (cnt == 2) dupli.push_back(c);
    else ans += c;
  }
  for (auto c : dupli) ans += c;
  for (auto c : dupli) ans += c;
  cout << ans << '\n';
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