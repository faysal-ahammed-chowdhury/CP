#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

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
  int n, m; cin >> n >> m;
  unordered_set<int, custom_hash> se;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    se.insert(x);
  }

  vector<array<int, 3>> Q;
  for (int i = 1; i <= m; i++) {
    int x, y, z; cin >> x >> y >> z;
    Q.push_back({x, y, z});
  }

  while (true) {
    bool ok = false;
    for (auto [x, y, z] : Q) {
      if (se.find(x) != se.end() and se.find(y) != se.end() and se.find(z) == se.end()) {
        se.insert(z);
        ok = true;
      }
    }
    if (ok == false) break;
  }

  cout << se.size() << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}