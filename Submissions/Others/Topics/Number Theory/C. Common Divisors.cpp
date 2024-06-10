#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll g = 0;
  for(int i = 0; i < n; i++) {
    ll x; cin >> x;
    g = __gcd(g, x);
  }

  int ans = 0;
  int lim = sqrt(g + 1);
  for(int i = 1; i <= lim; i++) {
    if(g % i == 0) {
      ans++;
      if(i != g / i) {
        ans++;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}