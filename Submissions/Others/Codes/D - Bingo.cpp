#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  if (n == 2 and k == 1) {
    cout << "YES\n";
    cout << "#.\n..\n";
    return 0;
  }
  if (n == 2 and k == 0) {
    cout << "YES\n";
    cout << "..\n..\n";
    return 0;
  }
  if (n == 2 and k >= 2) {
    cout << "NO\n";
    return 0;
  }
  int mx = (n * (n - 1));
  if (k <= mx) {
    cout << "YES\n";
    char a[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = '#';
      }
    }
    for (int i = 1; i <= n; i++) {
      a[i][i] = '.';
    }
    if (n % 2 == 0) {
      a[2][n - 1] = '.';
      a[n - 1][n - 1] = '#';
      a[2][2] = '#';
      a[n - 1][2] = '.';
    }
    int extra = mx - k;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (extra > 0 and a[i][j] == '#') {
          a[i][j] = '.';
          extra--;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
  else cout << "NO\n";

  return 0;
}