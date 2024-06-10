#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

using ll = long long;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(ll x) const { return x ^ RANDOM; }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  unordered_map<ll, int, chash> mp;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= 31; k++) {
      ll pw = (1ll << k);
      ll need = pw - a[i];
      ans += mp[need];
    }
    mp[a[i]]++;
  }

  cout << ans << '\n';

  return 0;
}