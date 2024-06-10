#include <bits/stdc++.h>
using namespace std;


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 4;
  int a[n + 1], pref[n + 1];
  pref[0] = 0;
  a[0] = 0;
  a[1] = 7;
  a[2] = 8;
  a[3] = 9;
  a[4] = 12;
  int l = 1, r = 3;
  for (int i = 1; i <= n; i++) {
    pref[i] = a[i];
    a[i] += a[i - 1];
  }

  for (int i = n, j = 1; i >= 1; i--, j++) {
    if (i == n) {
    }
    else {
      pref[i] = pref[i + 1] + (pref[i] * j);
    }
  }

  int ans = pref[l] - pref[r + 1];
  ans -= (n - r) * (a[r] - a[l - 1]);
  cout << ans << '\n';


  return 0;
}