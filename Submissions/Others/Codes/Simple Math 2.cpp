#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

  ll n, m; cin >> n >> m;
  int ans = power(10, n, m * m);
  ans = (ans / m) % m;
  cout << ans << '\n';

  return 0;
}