#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 

const int inf = 1e18;

void solve() {
  int n; cin >> n;
  int mn = inf, mx = -inf;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mn = min(mn, x);
    mx = max(mx, x);
  }

  int x; cin >> x;
  if (x >= mn and x <= mx) cout << "YES\n";
  else cout << "NO\n";
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