#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1], cnt[m + 1], divisor_cnt[m + 1];
  memset(cnt, 0, sizeof cnt);
  memset(divisor_cnt, 0, sizeof divisor_cnt);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > m) continue;
    cnt[a[i]]++;
  }

  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j += i) {
      divisor_cnt[j] += cnt[i];
    }
  }
  int l = 1, sz = 0;
  for (int i = 1; i <= m; i++) {
    if (divisor_cnt[i] > sz) {
      sz = divisor_cnt[i];
      l = i;
    }
  }
  cout << l << ' ' << sz << '\n';
  for (int i = 1; i <= n; i++) {
    if (l % a[i] == 0) cout << i << ' ';
  }
  cout << '\n';

  return 0;
}