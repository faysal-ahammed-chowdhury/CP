#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;

ll bigmod(ll a, ll b, ll p) {
  if(b == 0) return 1;
  if(b & 1) {
    ll val = bigmod(a, b / 2, p);
    return (((i128)val * val % p) * a) % p;
  }
  else {
    ll val = bigmod(a, b / 2, p);
    return ((i128)val * val) % p;
  }
}

ll modulo_inverse(ll b, ll p) {
  return bigmod(b, p - 2, p);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll a, b, p; cin >> a >> b >> p;
  ll ans1 = bigmod(a, b, p);
  ll ans2 = ((i128)a * b) % p;
  ll ans3 = ((i128)a * modulo_inverse(b, p)) % p;
  cout << ans1 << '\n';
  cout << ans2 << '\n';
  cout << ans3 << '\n';

  return 0;
}