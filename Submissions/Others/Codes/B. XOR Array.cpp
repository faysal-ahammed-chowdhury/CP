#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, l, r; cin >> n >> l >> r;
  int pref_xr[n + 1];
  for (int i = 0; i <= n; i++) {
    pref_xr[i] = i;
    if (i == r) pref_xr[i] = l - 1;
  }

  for (int i = 1; i <= n; i++) {
    cout << (pref_xr[i] ^ pref_xr[i - 1]) << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}