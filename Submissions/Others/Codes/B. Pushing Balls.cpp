#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 55;
int n, m;
string s[N];

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '@' + s[i];
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '0') continue;
      bool here = true;
      for (int k = 1; k <= i; k++) {
        here &= s[k][j] == '1';
      }
      if (here) continue;
      here = true;
      for (int k = 1; k <= j; k++) {
        here &= s[i][k] == '1';
      }
      ok &= here;
      // cout << i << ' ' << j << ' ' << here << '\n';
    }
  }

  if (ok) cout << "YES\n";
  else cout << "NO\n";
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