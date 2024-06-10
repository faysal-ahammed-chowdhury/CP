#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  if (s == t) {
    cout << s << '\n';
  }
  else if (s < t) {
    cout << s << '\n';
  }
  else {
    cout << t << s << '\n';
  }
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