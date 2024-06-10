#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1], r[n + 1];
  map<int, int> pos;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
    r[i] = n + 1;
  }

  while (m--) {
    int a, b; cin >> a >> b;
    a = pos[a];
    b = pos[b];
    if (a > b) swap(a, b);
    r[a] = min(r[a], b);
  }

  for (int i = n - 1; i >= 1; i--) {
    r[i] = min(r[i], r[i + 1]);
  }

  ll ans = 0;
  for (int l = 1; l <= n; l++) {
    ans += r[l] - l;
  }
  cout << ans << '\n';
  
  return 0;
}