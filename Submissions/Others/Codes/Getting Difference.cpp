#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int gc = 0, mx = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mx = max(mx, x);
    gc = __gcd(gc, x); 
  }
  if (k > mx) cout << "IMPOSSIBLE\n";
  else if (k % gc == 0) cout << "POSSIBLE\n";
  else cout << "IMPOSSIBLE\n";

  return 0;
}