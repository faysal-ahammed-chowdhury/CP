#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    int a[n + 1][m + 1];
    for(int i = n; i >= 1; i--) {
      for(int j = m; j >= 1; j--) {
        cin >> a[i][j];
      }
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        long long sum = 0;
        int k = 1, x = i - k, y = j - k;
        while(x >= 1 && y >= 1 && x <= n && y <= m) {
          sum += a[x][y];
          x--, y--;
        }
        x = i + k, y = j + k;
        while(x >= 1 && y >= 1 && x <= n && y <= m) {
          sum += a[x][y];
          x++, y++;
        }
        x = i + k, y = j - k;
        while(x >= 1 && y >= 1 && x <= n && y <= m) {
          sum += a[x][y];
          x++, y--;
        }
        x = i - k, y = j + k;
        while(x >= 1 && y >= 1 && x <= n && y <= m) {
          sum += a[x][y];
          x--, y++;
        }
        sum += a[i][j];
        ans = max(ans, sum);
      }
    }
    cout << ans << '\n';
  }

  return 0;
}