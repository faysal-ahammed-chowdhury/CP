#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, p; cin >> n >> p;
  map<ll, ll> mp;
  int lim = sqrt(p + 1);
  for(int i = 2; i <= lim; i++) {
    while(p % i == 0) {
      mp[i]++;
      p /= i;
    }
  }

  ll ans = 0;
  for(auto i: mp) {
    ll given = i.second / n;
    ans = max(ans, (ll)pow(i.first, given));
  }
  cout << ans << '\n';

  return 0;
}