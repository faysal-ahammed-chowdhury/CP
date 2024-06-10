#include <bits/stdc++.h>
using namespace std;

bool ok(string s, int k) {
  for (int i = 0, j = s.size() - 1; i < k; i++, j--) {
    if (s[i] != s[j]) return false;
  }
  return true;
}

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;

  if (k == 0) {
    cout << "YES\n";
    return;
  }

  int mn = k * 2 + 1;
  if (n < mn) {
    cout << "NO\n";
    return;
  }

  if (ok(s, k)) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
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