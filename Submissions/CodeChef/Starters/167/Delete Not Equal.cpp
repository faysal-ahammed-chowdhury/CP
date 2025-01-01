#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  bool all_same = true;
  for (int i = 1; i < n; i++) {
    all_same &= s[i] == s[i - 1];
  }
  cout << (all_same ? n : 1) << '\n';
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