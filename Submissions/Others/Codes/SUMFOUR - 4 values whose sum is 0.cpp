#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(int x) const { return x ^ RANDOM; }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n], b[n], c[n], d[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  gp_hash_table<int, int, chash> mp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mp[a[i] + b[j]]++;
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = c[i] + d[j];
      int need = -x;
      ans += mp[need];
    }
  }

  cout << ans << '\n';

  return 0;
}