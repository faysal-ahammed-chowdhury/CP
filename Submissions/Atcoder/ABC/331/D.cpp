#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, a[N][N];
long long prefix[N][N];

long long get_sum(int x1, int y1, int x2, int y2) {
  return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
}

long long fun(int row, int col) {
  long long sum1 = get_sum(1, 1, n, n);
  int row_cnt = row / n;
  int col_cnt = col / n;
  sum1 = 1ll * sum1 * row_cnt * col_cnt;
  int row_rem = row % n;
  int col_rem = col % n;
  long long sum2 = get_sum(1, 1, n, col_rem);
  sum2 = 1ll * sum2 * row_cnt;
  long long sum3 = get_sum(1, 1, row_rem, n);
  sum3 = 1ll * sum3 * col_cnt;
  long long sum4 = get_sum(1, 1, row_rem, col_rem);
  return sum1 + sum2 + sum3 + sum4;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c; cin >> c;
      if (c == 'B') a[i][j] = 1;
      else a[i][j] = 0;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
    }
  }

  while (q--) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a++, b++, c++, d++;
    long long ans = fun(c, d) - fun(a - 1, d) - fun(c, b - 1) + fun(a - 1, b - 1);
    cout << ans << '\n';
  }

  return 0;
}