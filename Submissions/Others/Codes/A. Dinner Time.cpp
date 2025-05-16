#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m, p, q; cin >> n >> m >> p >> q;
  int tot = (n + p - 1) / p;
  int x = tot * q;
  if (n % p) {
    cout << "Yes\n";
    return;
  }
  cout << (m == x ? "Yes\n" : "No\n");
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