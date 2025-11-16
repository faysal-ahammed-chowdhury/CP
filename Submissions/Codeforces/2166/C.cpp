#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  int ans = 0;
  int cnt = 0, mx_cnt = 0;
  a[0] = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == mx) mx_cnt++;
    if (a[i] == mx and a[i - 1] != mx) cnt++;
    if (a[i] == mx or a[i - 1] == mx) continue;
    if (i > 1) ans += max(a[i], a[i - 1]);
  }

  int segment = cnt - 1;
  int extra = (a[1] != mx) + (a[n] != mx);
  if (a[1] != mx and a[n] != mx) {
    ans += max(a[1], a[n]);
    extra--;
  }
  segment += extra;
  ans += mx * (segment + mx_cnt - 1);

  cout << ans << '\n';
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