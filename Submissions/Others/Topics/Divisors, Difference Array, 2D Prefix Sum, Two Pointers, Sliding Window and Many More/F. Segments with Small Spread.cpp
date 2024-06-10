#include <bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; ll s; cin >> n >> s;
  ll a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int r = 1; ll ans = 0;
  multiset<ll> ms;
  for (int l = 1; l <= n; l++) {
    while (r <= n) {
      ms.insert(a[r]);
      ll mx = *(--ms.end()), mn = *ms.begin();
      if (mx - mn > s) {
        ms.erase(ms.find(a[r]));
        break;
      }
      r++;
    }
    ans += r - l;
    ms.erase(ms.find(a[l]));
  }
  cout << ans << '\n';

  return 0;
}