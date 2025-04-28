#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = 10;
  sort(s.begin(), s.end());
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    int need = 10 - i, idx = -1, mn = 1e9;
    for (int j = 1; j <= 10; j++) {
      int x = s[j] - '0';
      if (x >= need and x <= mn) {
        idx = j;
        mn = x;
      }
    }
    s[idx] = '.';
    cout << mn;
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}