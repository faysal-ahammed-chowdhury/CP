#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();
  char last = s[0];
  int segment = last == '0';
  for (int i = 1; i < n; i++) {
    if (s[i] == '0' and last != '0') {
      segment++;
    }
    last = s[i];
  }

  if (segment == 0) {
    cout << 0 << '\n';
  }
  else if (segment == 1) {
    cout << 1 << '\n';
  }
  else {
    cout << 2 << '\n';
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