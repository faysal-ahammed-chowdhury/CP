#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int power(int x, int n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int S(int a, int r, int n) {
  int pw = 1 - power(r, n, mod);
  if (pw < 0) pw += mod;
  int lob = 1ll * a * pw % mod;
  int hor = (1 - r);
  if (hor < 0) hor += mod;
  return 1ll * lob * power(hor, mod - 2, mod) % mod;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, x; long long n; cin >> a >> b >> n >> x;
  int first_el = ((1ll * a * x % mod) + b) % mod;
  if (a == 1) {
    cout << ((1ll * (n % mod) * b % mod) + x) % mod << '\n';
    return 0;
  }
  if (n == 1) {
    cout << first_el << '\n';
    return 0;
  }
  int st = (((1ll * a * first_el % mod) + b) % mod) - first_el;
  if (st < 0) st += mod;
  n--;
  n %= mod - 1;
  int ans = (first_el + S(st, a, n)) % mod;
  cout << ans << '\n';

  return 0;
}