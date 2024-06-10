#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int power(int x, long long n, int mod) {
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int a, b, c; cin >> a >> b >> c;
    int x = power(b, c, mod - 1);
    cout << power(a, x, mod) << '\n';
  }

  return 0;
}