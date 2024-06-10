#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

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

int Sn(int a, int d, int n) {
  int x = 1ll * (1ll * n * (((a + a) % mod) + (1ll * (n - 1) * d % mod)) % mod) * power(2, mod - 2, mod) % mod;
  return x;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}