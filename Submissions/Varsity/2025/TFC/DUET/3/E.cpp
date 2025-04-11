#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 305;

int freq[N][N][N], org_freq[N];
ll pref[N][N][N];

int get(int k, int x1, int y1, int x2, int y2) {
  return pref[k][x2][y2] - pref[k][x1 - 1][y2] - pref[k][x2][y1 - 1] + pref[k][x1 - 1][y1 - 1];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, val; cin >> n >> m >> val;
  int nn, mm; cin >> nn >> mm;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x; cin >> x;
      freq[x][i][j] = 1;
      org_freq[x]++;
    }
  }

  for (int k = 1; k <= val; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        pref[k][i][j] = pref[k][i - 1][j] + pref[k][i][j - 1] - pref[k][i - 1][j - 1] + freq[k][i][j];
      }
    }
  }

  for (int i = 1; i + nn - 1 <= n; i++) {
    for (int j = 1; j + mm - 1 <= m; j++) {
      int ans = 0;
      for (int k = 1; k <= val; k++) {
        ans += org_freq[k] != get(k, i, j, i + nn - 1, j + mm - 1);
      }
      cout << ans << ' ';
    }
    cout << '\n';
  }

  return 0;
}