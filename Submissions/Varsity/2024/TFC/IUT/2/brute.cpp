#include <bits/stdc++.h>
using namespace std;

#define int long long
int N = 10005;

bool ok(int x) {
  int y = sqrt(x);
  stringstream ss;
  ss << x;
  string s1; ss >> s1;
  stringstream ss2;
  ss2 << y;
  string s2; ss2 >> s2;
  if (s1.substr(0, s2.length()) == s2) return true;
  return false;
}

void solve() {
  int n; cin >> n;
  int ans = 0;
  for (int i = 8; i <= n; i *= 10, i += 18) {
    int l = i * i;
    int r = (i + 1) * (i + 1);
    if (l > n) break;
    r = min(r, n);
    for (int j = l; j <= r; j++) {
      if (ok(j)) {
        cout << j << '\n';
        // cout << i << ' ' << (int)sqrt(i) << '\n';
        ans++;
      }
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}