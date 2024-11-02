#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1][m + 1], b[n + 1][m + 1], c[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c; cin >> c;
      a[i][j] = c - '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c; cin >> c;
      b[i][j] = c - '0';
    }
  }
  map<pair<int, int>, int> mp;
  mp[ {0, 0}] = 0;
  mp[ {0, 1}] = 1;
  mp[ {0, 2}] = 2;
  mp[ {1, 0}] = 2;
  mp[ {1, 1}] = 0;
  mp[ {1, 2}] = 1;
  mp[ {2, 0}] = 1;
  mp[ {2, 1}] = 2;
  mp[ {2, 2}] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      c[i][j] = mp[ {a[i][j], b[i][j]}];
    }
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    int cnt1 = 0, cnt2 = 0;
    for (int j = 1; j <= m; j++) {
      cnt1 += c[i][j] == 1;
      cnt2 += c[i][j] == 2;
    }
    ok &= (cnt1 % 3) == (cnt2 % 3);
  }
  for (int j = 1; j <= m; j++) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
      cnt1 += c[i][j] == 1;
      cnt2 += c[i][j] == 2;
    }
    ok &= (cnt1 % 3) == (cnt2 % 3);
  }
  if (ok) cout << "YES\n";
  else cout << "NO\n";
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