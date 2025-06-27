#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int l1, b1, l2, b2, l3, b3; cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
  if (l1 + l2 + l3 == b1 and b1 == b2 and b2 == b3) cout << "YES\n";
  else if (b1 + b2 + b3 == l1 and l1 == l2 and l2 == l3) cout << "YES\n";
  else if (l2 + l3 == l1 and b2 == b3 and b1 + b2 == l1) cout << "YES\n";
  else if (b2 + b3 == b1 and l2 == l3 and l1 + l2 == b1) cout << "YES\n";
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