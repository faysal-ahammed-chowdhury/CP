#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, q; cin >> n >> q;
  string s; cin >> s;
  s = '.' + s;

  bool all_a = true;
  for (int i = 1; i <= n; i++) {
    all_a &= s[i] == 'A';
  }

  while (q--) {
    int x; cin >> x;
    if (all_a) {
      cout << x << '\n';
      continue;
    }
    int cnt = 0;
    while (true) {
      bool done = false;
      for (int i = 1; i <= n; i++) {
        if (x == 0) {
          done = true;
          break;
        }
        cnt++;
        if (s[i] == 'A') x--;
        else x /= 2;
      }
      if (done) break;
    }
    cout << cnt << '\n';
  }
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