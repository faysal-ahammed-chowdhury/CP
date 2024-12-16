#include <bits/stdc++.h>
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q; cin >> n >> m >> q;
  int a[n + 1], b[m + 1];
  ll sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum1 += a[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    sum2 += b[i];
  }

  unordered_set<ll, custom_hash> se1, se2;
  for (int i = 1; i <= n; i++) {
    se1.insert(sum1 - a[i]);
  }

  for (int i = 1; i <= m; i++) {
    se2.insert(sum2 - b[i]);
  }

  while (q--) {
    int x; cin >> x;
    int xx =  abs(x);
    bool ok = false;
    for (int i = 1; i * i <= xx; i++) {
      if (xx % i == 0) {
        int d1 = i, d2 = x / i;
        for (auto y : {-d1, d1}) {
          for (auto z : {d2, -d2}) {
            if (y * z == x and se1.find(y) != se1.end() and se2.find(z) != se2.end()) {
              ok = true;
              goto go; // nice trick, learned from amirhozaifa bhai's code, thanks bhai :)
            }
            if (y * z == x and se1.find(z) != se1.end() and se2.find(y) != se2.end()) {
              ok = true;
              goto go; 
            }
          }
        }
      }
    }
    go:;
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}