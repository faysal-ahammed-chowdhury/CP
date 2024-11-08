#include <bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;

const int N = 2e5 + 9; 
const ll inf = 1e18 + 9; 

int cs;
void solve() {
  int n, q; cin >> n >> q;
  ll a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (q--) {
    ll l, r, m; cin >> l >> r >> m;
    for (int i = l; i <= r; i++) {
      a[i] /= m;
    }
  }
  cout << "Case " << ++cs << ": ";
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
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