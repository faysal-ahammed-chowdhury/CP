#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a, b; cin >> n >> a >> b;
  if ((abs(a - b)) & 1) cout << "NO\n";
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