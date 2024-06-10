#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define ll long long

bool ok(ll x, ll y, ll r) {
  ll ans = (x * x) + (2 * x * y) + x + 1;
  return ans == r;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll r; cin >> r;
  for(ll x = 1; x * x <= r; x++) {
    ll y = (r - 1 - x - (x * x)) / (x + x);

    if(y > 0 && ok(x, y, r)) {
      cout << x << ' ' << y << '\n';
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}