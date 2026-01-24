#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m, h; cin >> n >> m >> h;
  int a[n + 1], b[m + 1], c[m + 1], last_upd[n + 1], tmp[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tmp[i] = a[i];
    last_upd[i] = -1;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i] >> c[i];
  }

  int last = -2;
  for (int i = 1; i <= m; i++) {
    int idx = b[i], x = c[i];
    if (last_upd[idx] <= last) tmp[idx] = a[idx];
    tmp[idx] += x;
    last_upd[idx] = i;
    if (tmp[idx] > h) {
      last = i;
      tmp[idx] = a[idx];
    }
  }

  for (int i = max(1, last + 1); i <= m; i++) {
    int idx = b[i], x = c[i];
    a[idx] += x;
  }

  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  } cout << '\n';
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