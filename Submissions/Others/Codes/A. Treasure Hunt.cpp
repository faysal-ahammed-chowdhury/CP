#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int x, y, a; cin >> x >> y >> a;
  int tot = x + y;
  a++;

  a %= tot;

  if (a <= x and a > 0) cout << "NO\n";
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