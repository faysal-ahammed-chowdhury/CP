#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9;
using ll = long long;

ll reduce(ll n) {
  while(n > 0 && n % 10 == 0) {
    n /= 10;
  }
  return n % mod;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while(cin >> n >> m) {
    ll ans = 1;
    for(int i = n; i >= (n - m + 1); i--) {
      ans = ans * i;
      ans = reduce(ans);
    }
    cout << ans % 10 << '\n';
  }

  return 0;
}