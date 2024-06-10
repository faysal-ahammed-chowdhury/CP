#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  if (s[0] == s[n - 1]) {
    cout << n - 2 << '\n';
  }
  else {
    cout << n - 1 << '\n';
  }
}

int32_t main() {
  // freopen("max-pair.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}