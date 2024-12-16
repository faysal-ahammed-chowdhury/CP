#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  for (auto &c : s) {
    if (c == 'p') c = 'q';
    else if (c == 'q') c = 'p';
  }
  reverse(s.begin(), s.end());
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