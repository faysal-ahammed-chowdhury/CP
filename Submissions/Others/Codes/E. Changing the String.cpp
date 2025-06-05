#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  string s; cin >> s;
  set<int> ba, bc, ca, cb;
  for (int i = 1; i <= m; i++) {
    char a, b; cin >> a >> b;
    if (a == 'a') continue;
    if (a == 'b' and b == 'a') ba.insert(i);
    else if (a == 'b' and b == 'c') bc.insert(i);
    else if (a == 'c' and b == 'a') ca.insert(i);
    else if (a == 'c' and b == 'b') cb.insert(i);
  }

  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') continue;
    if (s[i] == 'b') {
      if (!ba.empty()) {
        ba.erase(ba.begin());
        s[i] = 'a';
        continue;
      }
      if (!bc.empty() and !ca.empty()) {
        int x = *bc.begin();
        auto it = ca.upper_bound(x);
        int y = (it != ca.end() ? *it : 0);
        if (x < y) {
          bc.erase(bc.begin());
          ca.erase(y);
          s[i] = 'a';
          continue;
        }
      }
    }
    else if (s[i] == 'c') {
      if (!ca.empty()) {
        ca.erase(ca.begin());
        s[i] = 'a';
        continue;
      }
      if (!cb.empty() and !ba.empty()) {
        int x = *cb.begin();
        auto it = ba.upper_bound(x);
        int y = (it != ba.end() ? *it : 0);
        if (x < y) {
          cb.erase(cb.begin());
          ba.erase(y);
          s[i] = 'a';
          continue;
        }
      }
      if (!cb.empty()) {
        cb.erase(cb.begin());
        s[i] = 'b';
      }
    }
  }

  cout << s << '\n';
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