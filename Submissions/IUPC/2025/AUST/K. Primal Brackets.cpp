#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N], pref[N];

void solve() {
  int n, q; cin >> n >> q;
  int nn = n + n;
  for (int i = 1; i <= nn; i++) {
    cin >> a[i];
    if (a[i] < 0 and a[i - 1] >= 0) pref[i] = 1;
    else pref[i] = 0;
    pref[i] += pref[i - 1];
  }

  while (q--) {
    int l, r; cin >> l >> r;
    cout << pref[r] - pref[l - 1] << '\n';
  }
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