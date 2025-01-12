#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  string s; cin >> s;
  ll a[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int path[n + 1][m + 1];
  memset(path, -1, sizeof path);
  int i = 1, j = 1;
  path[i][j] = 1;
  for (auto c : s) {
    if (c == 'R') j++;
    else i++;
    path[i][j] = 1;
  }

  int row[n + 1], col[m + 1];
  memset(row, 0, sizeof row);
  memset(col, 0, sizeof col);
  ll sum_row[n + 1], sum_col[m + 1];
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    ll sum = 0;
    for (int j = 1; j <= m; j++) {
      cnt += path[i][j] == 1;
      sum += a[i][j];
    }
    if (cnt == 1) row[i] = 1;
    sum_row[i] = sum;
  }

  for (int j = 1; j <= m; j++) {
    int cnt = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
      cnt += path[i][j] == 1;
      sum += a[i][j];
    }
    if (cnt == 1) col[j] = 1;
    sum_col[j] = sum;
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << row[i] << ' ';
  // }
  // cout << '\n';
  // for (int i = 1; i <= m; i++) {
  //   cout << col[i] << ' ';
  // }
  // cout << '\n';

  i = 1, j = 1;
  if (row[i]) {
    a[i][j] = -sum_row[i];
  }
  else if (col[j]) {
    a[i][j] = -sum_col[j];
  }

  for (auto c : s) {
    if (c == 'R') j++;
    else i++;
    if (row[i]) {
      a[i][j] = -sum_row[i];
    }
    if (col[j]) {
      a[i][j] = -sum_col[j];
    }
  }

  for (int i = 1; i <= n; i++) {
    ll sum = 0;
    for (int j = 1; j <= m; j++) {
      sum += a[i][j];
    }
    sum_row[i] = sum;
  }

  for (int j = 1; j <= m; j++) {
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += a[i][j];
    }
    sum_col[j] = sum;
  }

  i = 1, j = 1;
  char prev;
  for (auto c : s) {
    if (c == 'R') j++;
    else i++;
    if (!row[i] and !col[j]) {
      if (c == 'D') {
        a[i][j] = -sum_col[j];
        sum_col[j] += a[i][j];
        sum_row[i] += a[i][j];
      }
      else {
        a[i][j] = -sum_row[i];
        sum_row[i] += a[i][j];
        sum_col[j] += a[i][j];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i][j] << ' ';
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