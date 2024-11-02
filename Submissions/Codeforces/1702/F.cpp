#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

void solve() {
  int n; cin >> n;
  int a[n + 1];
  gp_hash_table<int, int, custom_hash> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    while (x > 0) {
      int y = x;
      bool flag = false;
      while (y <= 1e9) {
        if (mp.find(y) != mp.end() and mp[y] > 0) {
          mp[y]--;
          if (mp[y] == 0) mp.erase(y);
          flag = 2;
          cnt++;
          break;
        }
        y *= 2;
      }
      if (flag) break;
      x /= 2;
    }
  }
  if (cnt == n) cout << "YES\n";
  else cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}