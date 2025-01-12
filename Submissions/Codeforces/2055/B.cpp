#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int idx = -1;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] > a[i]) {
      cnt++;
      idx = i;
    }
  }

  
  if (cnt == 0) cout << "YES\n";
  else if (cnt > 1) cout << "NO\n";
  else {
    bool ok = true;
    ll x = b[idx] - a[idx];
    for (int i = 1; i <= n; i++) {
      if (i == idx) continue;
      ok &= (a[i] - x) >= b[i];
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
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