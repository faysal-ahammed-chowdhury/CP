#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], b[N], ans[N + N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  int i = 1, j = 1, now = 1;
  while (i <= n and j <= m) {
    if (a[i] < b[j]) {
      ans[now++] = a[i++];
    }
    else {
      ans[now++] = b[j++];
    }
  }

  while (i <= n) ans[now++] = a[i++];
  while (j <= m) ans[now++] = b[j++];

  for (int i = 1; i <= n + m; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}