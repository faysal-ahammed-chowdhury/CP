#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (a[i] < b[i]) swap(a[i], b[i]);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) ans += a[i];
  sort(b + 1, b + n + 1);
  reverse(b + 1, b + n + 1);
  for (int i = 1; i <= k - 1; i++) {
    ans += b[i];
  }

  cout << ++ans << '\n';
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