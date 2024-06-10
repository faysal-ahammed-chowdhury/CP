#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(int x) const { return x ^ RANDOM; }
};

int power(int b, int p, int m) {
  if (p == 0) return 1 % m;
  if (p & 1) {
    int val = power(b, p / 2, m);
    return ((1LL * val * val) % m) * b % m;
  }
  else {
    int val = power(b, p / 2, m);
    return (1LL * val * val) % m;
  }
}

void solve() {
  int n, x; cin >> n >> x;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  
  int candidate = *max_element(a + 1, a + n + 1);

  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] * a[i] % x;
  }

  int len = 1e9, ans = 0;
  for (int mx = x - 1; mx >= candidate; mx--) {
    gp_hash_table<int, int, chash> mp;
    int z = power(mx, x - 2, x);
    for (int i = 1; i <= n; i++) {
      if (mx == a[i]) {
        len = min(len, i);
      }
      int y = a[i] * z % x;
      if (mp.find(y) != mp.end()) {
        len = min(len, i - mp[y]);
      }
      mp[a[i]] = i;
    }
    if (len != 1e9) {
      ans = mx;
      break;
    }
  }

  if (ans == candidate) {
    len = 1;
  }
  cout << ans << ' ' << len << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}