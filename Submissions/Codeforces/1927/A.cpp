#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int st = -1, en = -1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'B') {
      st = i;
      break;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (s[i] == 'B') {
      en = i;
      break;
    }
  }

  if (st == -1) {
    cout << 0 << '\n';
  }
  else {
    cout << en - st + 1 << '\n';
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