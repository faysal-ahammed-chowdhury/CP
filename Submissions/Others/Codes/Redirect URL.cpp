#include <bits/stdc++.h>
using namespace std;

int cs = 0;
void solve() {
  string s; cin >> s;
  cout << "Case " << ++cs << ": ";
  if (s[4] == ':') {
    cout << "https" << s.substr(4) << '\n';
  }
  else {
    cout << s << '\n';
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