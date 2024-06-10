#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  int a[n + 1][m + 1], b[m + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c; cin >> c;
      if (c == 'x') {
        a[i][j] = 0;
      }
      else if (c == '.') {
        a[i][j] = 1;
      }
      else {
        a[i][j] = 2;
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      b[i][j] = a[j][i];
    }
  }

  array<int, 3> freq[n + 1][m + 1];
  memset(freq, 0, sizeof(freq));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      freq[i][j][a[i][j]]++;
      freq[i][j][0] += freq[i][j - 1][0];
      freq[i][j][1] += freq[i][j - 1][1];
      freq[i][j][2] += freq[i][j - 1][2];
    }
  }

  int ans = inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j + k - 1 <= m; j++) {
      if ((freq[i][j + k - 1][0] - freq[i][j - 1][0]) == 0) {
        ans = min(ans, freq[i][j + k - 1][1] - freq[i][j - 1][1]);
      }
    }
  }

  array<int, 3> freq2[m + 1][n + 1];
  memset(freq2, 0, sizeof(freq2));

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      freq2[i][j][b[i][j]]++;
      freq2[i][j][0] += freq2[i][j - 1][0];
      freq2[i][j][1] += freq2[i][j - 1][1];
      freq2[i][j][2] += freq2[i][j - 1][2];
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j + k - 1 <= n; j++) {
      if ((freq2[i][j + k - 1][0] - freq2[i][j - 1][0]) == 0) {
        ans = min(ans, freq2[i][j + k - 1][1] - freq2[i][j - 1][1]);
      }
    }
  }

  cout << ((ans == inf) ? -1 : ans) << '\n';

  return 0;
}