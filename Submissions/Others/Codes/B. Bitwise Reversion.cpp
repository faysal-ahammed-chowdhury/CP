#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int x, y, z; cin >> x >> y >> z;
  int a = x | z;
  int b = x | y;
  int c = y | z;

  if ((a & b) == x and (b & c) == y and (c & a) == z) cout << "YES\n";
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