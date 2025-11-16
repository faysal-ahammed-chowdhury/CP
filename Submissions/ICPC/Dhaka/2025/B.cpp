#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int a, v, l, n; cin >> a >> v >> l >> n;
  if (min(v - 1, a - 1) < n) cout << "NO\n";
  else cout << "YES\n";
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