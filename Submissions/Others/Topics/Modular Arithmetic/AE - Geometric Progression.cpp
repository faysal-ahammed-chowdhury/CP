#include <bits/stdc++.h>
using namespace std;

#define ll long long
int power(int x, ll n, int mod) {
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

int fun(int a, ll x, int mod) {
  if (x == 0) {
    return 1 % mod;
  }
  if (x & 1) {
    ll mid = x / 2;
    int cur = fun(a, mid, mod);
    int ans = (cur + 1ll * cur * power(a, mid + 1, mod) % mod) % mod;
    return ans;
  }
  else {
    int ans = (fun(a, x - 1, mod) + power(a, x, mod)) % mod;
    return ans;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, m; ll x; cin >> a >> x >> m;
  cout << fun(a, x - 1, m);

  return 0;
}