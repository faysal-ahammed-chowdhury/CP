#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int sq = sqrt(n);
  while (sq * sq < n) sq++;
  while (sq * sq > n) sq--;
  if (sq * sq != n) {
    cout << "NO\n";
    return;
  }
  bool ok = true;
  for (int i = 0; i < sq; i++) {
    ok &= s[i] == '1';
  }
  for (int i = n - 1, j = 0; j < sq; i--, j++) {
    ok &= s[i] == '1';
  }
  for (int i = 1; i <= sq - 2; i++) {
    for (int j = sq * i, k = 1; k <= sq; j++, k++) {
      if (j == sq * i or j == (sq * (i + 1)) - 1) {
        ok &= s[j] == '1';
        continue;
      }
      ok &= s[j] == '0';
    }
  }
  if (ok) cout << "Yes\n";
  else cout << "No\n";
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