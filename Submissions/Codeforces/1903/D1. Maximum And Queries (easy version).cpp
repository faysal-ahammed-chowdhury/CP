#include <bits/stdc++.h>
using namespace std;

#define int long long
const int K = 60;

int on_cost(int n, int k) {
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    if (n & (1ll << i)) ans += (1ll << i);
  }
  return (1ll << k) - ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  int a[n + 1], b [n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  while (q--) {
    for (int i = 1; i <= n; i++) {
      a[i] = b[i];
    }
    vector<int> vec;
    bool changed[n + 1];
    memset(changed, 0, sizeof changed);
    long long max_k; cin >> max_k;
    for (int k = K; k >= 0; k--) {
      unsigned long long need = 0;
      for (int i = 1; i <= n; i++) {
        if (changed[i]) {
          need += (1ll << k);
        }
        else if (!(a[i] & (1ll << k))) {
          int x = on_cost(a[i], k);
          need += x;
        }
        if (need > max_k) break;
      }
      if (need <= max_k) {
        vec.push_back(k);
        max_k -= need;
        for (int i = 1; i <= n; i++) {
          if (!(a[i] & (1ll << k)) and !changed[i]) {
            changed[i] = true;
            for (int x = k; x >= 0; x--) {
              a[i] = (a[i] & ~(1ll << (x - 1)));
            }
          }
        }
      }
    }
    int ans = 0;
    for (auto x : vec) {
      ans += (1ll << x);
    }
    cout << ans << '\n';
  }

  return 0;
}