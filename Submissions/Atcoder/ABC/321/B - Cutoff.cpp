#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int inf = 1e9;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  int a[n];
  int sum = 0, mx = -inf, mn = inf;
  for(int i = 1; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }

  sum -= mx + mn;

  if(sum + mn >= x) {
    cout << 0 << '\n';
    return 0;
  }
  if(sum + mx == x) {
    cout << mx << '\n';
    return 0;
  }

  if(sum + mx < x) {
    cout << -1 << '\n';
    return 0;
  }

  int need = x - sum;
  cout << max(0, need) << '\n';

  return 0;
}