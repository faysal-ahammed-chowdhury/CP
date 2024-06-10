#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, l, r; cin >> n >> m >> l >> r;
  i128 lc = (__int128(n) * m) / __gcd(n, m);
  ll cnt = r / lc;
  cnt -= (l / lc);
  if(l % lc == 0) cnt++;
  cout << cnt << '\n';

  return 0;
}