#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1][n + 1];
  memset(a, -1, sizeof a);

  int i = (n + 1) / 2, j = i;
  a[i][j] = 0;
  int cnt = 1;
  for (int tmp = 2; tmp <= n; tmp++) {
    int x = tmp - 1;
    if (tmp & 1) {
      --j;
      a[i][j] = cnt++;
      for (int k = 1; k <= x; k++) {
        --i;
        a[i][j] = cnt++;
      }
      for (int k = 1; k <= x; k++) {
        ++j;
        a[i][j] = cnt++;
      }
    }
    else {
      ++j;
      a[i][j] = cnt++;
      for (int k = 1; k <= x; k++) {
        ++i;
        a[i][j] = cnt++;
      }
      for (int k = 1; k <= x; k++) {
        --j;
        a[i][j] = cnt++;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << ' ';
      // assert(a[i][j] != -1);
    }
    cout << '\n';
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