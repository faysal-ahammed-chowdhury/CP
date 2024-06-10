#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  sort(s.begin(), s.end());
  if (s[0] == '1' and s.front() == s.back()) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
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