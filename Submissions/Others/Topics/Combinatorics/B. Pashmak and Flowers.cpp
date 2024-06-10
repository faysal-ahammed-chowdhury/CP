#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(int x) const { return x ^ RANDOM; }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  gp_hash_table<int, int, chash> mp;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  sort(a + 1, a + n + 1);

  int d = a[n] - a[1];
  cout << d << ' ';
  if (d == 0) {
    cout << (1ll * n * (n - 1)) / 2;
  }
  else {
    cout << 1ll * mp[a[1]] * mp[a[n]] << '\n';
  }

  return 0;
}