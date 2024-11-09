#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 9, mod = 998244353;
int a[N], b[N], n;

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

int inverse(int x) {
  return power(x, mod - 2, mod);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int inv2 = inverse(2);
  int invn = inverse(n);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = inv2 * (a[i] + b[i] % mod) % mod;
    int z = x * invn % mod;
    ans += z;
    ans %= mod;
  }
  for (int i = 1; i <= n; i++) {
    cout << ans * i % mod;
    if (i != n) cout << ' ';
  }
  cout << '\n';

  return 0;
} 