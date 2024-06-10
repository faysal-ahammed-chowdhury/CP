#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

void solve() {
  ll n; cin >> n;
  ll x = n;
  while (true) {
    ll sum = 0;
    ll tmp = x;
    while (tmp > 0) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if (__gcd(x, sum) > 1) {
      cout << x << '\n';
      return;
    }
    x++;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}