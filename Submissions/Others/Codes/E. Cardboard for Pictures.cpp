#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, c;

bool ok(__int128 w, vector<ll> &v) {
  __int128 calc = 0;
  for(auto i: v) {
    calc +=  __int128(i + w + w) * (i + w + w);
  }
  return calc >= __int128(c);
}

void solve() {
  cin >> n >> c;
  vector<ll> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }

  __int128 l = 0, r = 1e14;
  ll ans = -1;
  while(l <= r) {
    __int128 mid = (l + r) / 2;
    if(ok(mid, v)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}