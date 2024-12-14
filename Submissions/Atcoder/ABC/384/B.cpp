#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, r; cin >> n >> r;
  for (int i = 1; i <= n; i++) {
    int d, x; cin >> d >> x;
    if (d == 1) {
      if (r >= 1600 and r <= 2799) r += x;
    }
    else {
      if (r >= 1200 and r <= 2399) r += x;
    }
  }

  cout << r << '\n';

  return 0;
}   