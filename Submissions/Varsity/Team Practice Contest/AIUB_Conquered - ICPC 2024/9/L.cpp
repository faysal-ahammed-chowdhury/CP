#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1], b[m + 1], W[n + 1][m + 1];
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> W[i][j];
      mx = max(mx, W[i][j]);
      if (i == 1) b[j] = W[i][j];
    }
  }

  int k = 1e9 + 7;
  for (int i = 2; i <= n; i++) {
    set<int> pos, neg;
    for (int j = 1; j <= m; j++) {
      int x = W[i][j] - W[i - 1][j];
      if (x < 0) neg.insert(x);
      else pos.insert(x);
    }
    if (pos.size() > 1 or neg.size() > 1) {
      cout << "NO\n";
      return 0;
    }
    if (pos.size() == 1 and neg.size() == 1) {
      int d = *pos.begin() - *neg.begin();
      k = d;
    }
  }

  if (k <= mx) {
    cout << "NO\n";
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      a[i] = (W[i][j] - b[j]);
      if (a[i] < 0) a[i] += k;
    }
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ok &= W[i][j] == (a[i] + b[j]) % k;
    }
  }

  if (ok) {
    cout << "YES\n";
    cout << k << '\n';
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    for (int j = 1; j <= m; j++) {
      cout << b[j] << ' ';
    }
    cout << '\n';
  }
  else cout << "NO\n";


  return 0;
}