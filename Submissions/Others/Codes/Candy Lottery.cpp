#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// almost correct solution - precision error
long double p(long double x, long double n, long double k) {
  return pow((x / (long double)k), n) - pow(((x - 1) / (long double)k), n);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  long double ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += p(i, n, k) * i;
  }
  cout << fixed << setprecision(6);
  cout << ans << '\n';

  return 0;
}