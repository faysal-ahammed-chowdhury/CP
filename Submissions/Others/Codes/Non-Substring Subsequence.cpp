#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, q; cin >> n >> q;
  string s; cin >> s;
  s = '.' + s;
  while (q--) {
    int l, r; cin >> l >> r;
    char starts = s[l], ends = s[r];
    bool done = false;
    for (int i = 1; i < l; i++) {
      if (s[i] == starts) {
        cout << "YES\n";
        done = true;
        break;
      }
    }
    for (int i = r + 1; !done and i <= n; i++) {
      if (s[i] == ends) {
        cout << "YES\n";
        done = true;
        break;
      }
    }

    if (!done) {
      cout << "NO\n";
    }
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