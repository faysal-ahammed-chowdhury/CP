#include <bits/stdc++.h>
using namespace std;

long long __lcm(long long a, long long b) {
  return (1ll * a * b) / __gcd(a, b);
}

int cs;
void solve() {
  long long a, b, l; cin >> a >> b >> l;
  long long lc = __lcm(a, b);
  cout << "Case " << ++cs << ": ";
  if (l % lc != 0) cout << "impossible\n";
  else {
    long long tmp1 = l, tmp2 = lc, ans = 1;
    for (long long i = 2; 1ll * i * i <= l; i++) {
      long long p = i, e1 = 0, e2 = 0;
      long long x = 1;
      while (tmp1 % p == 0) {
        x *= p;
        e1++;
        tmp1 /= p;
      }
      while (tmp2 % p == 0) {
        e2++;
        tmp2 /= p;
      }
      if (e1 != e2) {
        ans *= x;
      }
    }
    if (tmp1 != tmp2) {
      ans *= tmp1;
    }
    cout << ans << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}