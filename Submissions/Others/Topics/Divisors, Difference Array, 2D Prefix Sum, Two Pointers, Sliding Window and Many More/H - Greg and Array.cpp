#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
long long diff[N];
int a[N], op[N], l[N], r[N], d[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i] >> d[i];
  }

  while (k--) {
    int i, j; cin >> i >> j;
    op[i]++;
    op[j + 1]--;
  }

  for (int i = 1; i <= m; i++) {
    op[i] += op[i - 1];
  }

  for (int i = 1; i <= m; i++) {
    diff[l[i]] += 1ll * d[i] * op[i];
    diff[r[i] + 1] -= 1ll * d[i] * op[i];
  }

  for (int i = 1; i <= n; i++) {
    diff[i] += diff[i - 1];
    cout << a[i] + diff[i] << ' ';
  }
  cout << '\n';

  return 0;
}