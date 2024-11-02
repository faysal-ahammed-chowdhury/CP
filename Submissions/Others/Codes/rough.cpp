#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int idx, k; cin >> idx >> k;
  int mod = (1 << idx);
  int xr = 0;
  for (int i = 0; i <= 28; i++) {
    if ((i % mod) == k) {
      xr ^= i;
      cout << xr << '\n';
    }
  }

  return 0;
}