#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
const int N = 2e5 + 9;
int a[N];

int solve(int r) {
  int msb = __lg(r);
  int x = (1ll << msb);

  int cur = x - 1;
  for (int i = x; i <= r; i++) {
    a[i] = cur;
    a[cur] = i;
    cur--;
  }

  return cur;
}

void solve() {
  int l, r; cin >> l >> r;
  int n = r - l + 1;

  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }

  int cur = r;
  while (cur > 0) {
    cur = solve(cur);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] | i;
  }

  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
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