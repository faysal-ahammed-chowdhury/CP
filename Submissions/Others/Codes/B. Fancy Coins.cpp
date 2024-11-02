#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int m, k, a1, ak; cin >> m >> k >> a1 >> ak;
    int possible_k = min(m / k, ak);
    m -= (k * possible_k);
    m -= a1;
    if(m <= 0) {
      cout << 0 << '\n';
      continue;
    }

    int less = k - ((m % k) == 0 ? k : (m % k));
    if(a1 >= less) {
      int ans = (m + less) / k;
      cout << ans << '\n';
    }
    else {
      int ans = m / k;
      m %= k;
      ans += m;
      cout << ans << '\n';
    }
  }

  return 0;
}