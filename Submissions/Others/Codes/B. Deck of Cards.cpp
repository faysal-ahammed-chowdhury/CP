#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s = '.' + s;
  int l = 1, r = n;

  if (k == n) {
    for (int i = 1; i <= n; i++) {
      cout << '-';
    }
    cout << '\n';
    return;
  }

  char ans[n + 1];
  for (int i = 1; i <= n; i++) {
    ans[i] = '+';
  }

  for (int i = 1; i <= k; i++) {
    if (s[i] == '0') {
      ans[l++] = '-';
    }
    else if (s[i] == '1') {
      ans[r--] = '-';
    }
  }

  for (int i = 1; i <= k; i++) {
    if (s[i] == '2') {
      // cout << l << ' ' << r << '\n';
      ans[l++] = '?';
      ans[r--] = '?';
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << '\n';
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