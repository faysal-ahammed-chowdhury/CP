#include <bits/stdc++.h>
using namespace std;

const int N = 1005, K = 30;
int a[N], matrix[N][N];

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> matrix[i][j];
      if (i == j) continue;
      a[i] |= matrix[i][j];
      a[j] |= matrix[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      a[i] &= matrix[i][j];
      a[j] &= matrix[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (matrix[i][j] != (a[i] | a[j])) {
        cout << "No\n";
        return;
      }
    }
  }

  cout << "Yes\n";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
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