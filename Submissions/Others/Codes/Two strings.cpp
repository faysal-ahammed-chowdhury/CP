#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a, b; cin >> a >> b;
  int n = a.size(), m = b.size();
  a = '.' + a, b = '.' + b;
  int min_idx[m + 1], min_idx_rev[m + 1];
  memset(min_idx, -1, sizeof min_idx);
  memset(min_idx_rev, -1, sizeof min_idx_rev);
  for (int i = 1, j = 1; i <= m and j <= n; i++, j++) {
    while (b[i] != a[j] and j <= n) j++;
    if (j <= n) min_idx[i] = j;
  }
  for (int i = m, j = n; i >= 1 and j >= 1; i--, j--) {
    while (b[i] != a[j] and j >= 1) j--;
    if (j >= 1) min_idx_rev[i] = j;
  }
  int ans = 1e9, start = -1;
  for (int i = 1; i <= m; i++) {
    int l = min_idx[i];
    int right_cnt = &min_idx_rev[m + 1] - upper_bound(min_idx_rev + 1, min_idx_rev + m + 1, l);
    if (l != -1) {
      int rem = m - (i + right_cnt);
      if (rem <= ans) {
        ans = rem;
        start = i + 1;
      }
    }
  }
  int suffix_cnt = 0;
  for (int i = m; i >= 1; i--) {
    if (min_idx_rev[i] == -1) break;
    suffix_cnt++;
  }
  int rem2 = m - suffix_cnt;
  if (suffix_cnt == 0 and start == -1) cout << "-\n";
  else if (rem2 <= ans) {
    for (int i = rem2 + 1; i <= m; i++) cout << b[i];
    cout << '\n';
  }
  else {
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
      if (i >= start and cnt < ans) {
        cnt++;
        continue;
      }
      cout << b[i];
    }
    cout << '\n';
  }

  return 0;
}