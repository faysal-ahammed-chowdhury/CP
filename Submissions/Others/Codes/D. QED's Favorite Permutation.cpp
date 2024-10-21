#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1], pref[n + 1], suff[n + 2];
  pref[0] = 0;
  suff[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = max(pref[i - 1], a[i]);
  }
  for (int i = n; i >= 1; i--) {
    suff[i] = min(suff[i + 1], a[i]);
  }

  string s; cin >> s;
  s = '.' + s;

  set<int> se;

  for (int i = 1; i <= n; i++) {
    if (s[i] == 'L' and s[i + 1] == 'R') {
      if (pref[i] > suff[i + 1]) {
        se.insert(i);
      }
    }
  }

  while (q--) {
    int i; cin >> i;
    int idx = i;
    if (s[idx] == 'L') {
      if (s[idx + 1] == 'R') se.erase(idx);
      if (s[idx - 1] == 'L') {
        if (pref[idx - 1] > suff[idx]) se.insert(idx - 1);
      }
      s[idx] = 'R';
    }
    else {
      if (s[idx - 1] == 'L') se.erase(idx - 1);
      if (s[idx + 1] == 'R') {
        if (pref[idx] > suff[idx + 1]) se.insert(idx);
      }
      s[idx] = 'L';
    }

    if (se.empty()) cout << "YES\n";
    else cout << "NO\n";
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