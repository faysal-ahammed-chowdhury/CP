#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int gc = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    gc = __gcd(gc, x);
  }
  cout << gc << '\n';

  return 0;
}