#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  bool flag = false;
  int idx = -1;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (c == '0') {
      idx = i;
      flag = true;
      break;
    }
  }
  if (flag) {
    for (int i = 0; i < idx; i++) {
      cout << "IDK\n";
    }
    for (int i = idx; i < n; i++) {
      cout << "NO\n";
    }
  }
  else {
    for (int i = 1; i < n; i++) {
      cout << "IDK\n";
    }
    cout << "YES\n";
  }
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