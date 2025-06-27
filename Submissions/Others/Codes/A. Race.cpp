#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int a, x, y; cin >> a >> x >> y;
  if (x > y) swap(x, y);
  if (a >= x and a <= y) cout << "NO\n";
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