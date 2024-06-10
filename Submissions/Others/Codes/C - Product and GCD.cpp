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
  if(p > 1) mp[p]++;

  ll ans = 1;
  for(auto i: mp) {
    // cout << i.first << ' ' << i.second << '\n';
    ll given = i.second / n;
    ans *= (ll)pow(i.first, given);
  }
  cout << ans << '\n';

  return 0;
}