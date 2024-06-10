#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string a, b; cin >> a >> b;
  int n = a.size(), m = b.size();
  a = '.' + a, b = '.' + b;

  int pref[m + 1];
  pref[0] = 0;
  for (int i = 1; i <= m; i++) {
    pref[i] = pref[i - 1] + (b[i] == '1');
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = i - 1, r = n - i;
    r = m - r;
    int one = pref[r] - pref[l];
    int zero = (r - l) - one;

    if (a[i] == '0') {
      ans += one;
    }
    else {
      ans += zero;
    }
  }

  cout << ans << '\n';

  return 0;
}