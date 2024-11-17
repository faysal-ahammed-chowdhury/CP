#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int k; cin >> k;
  map<int, int> mp;
  for (int i = 1; i <= k; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  int n = k - 2;
  for (int i = 1; 1ll * i * i <= n; i++) {
    if (n % i == 0) {
      if (i == (n / i) and mp.find(i) != mp.end() and mp[i] >= 2) {
        cout << i << ' ' << (n / i) << '\n';
        return;
      }
      if (i != (n / i) and mp.find(i) != mp.end() and mp.find(n / i) != mp.end()) {
        cout << i << ' ' << (n / i) << '\n';
        return;
      }
    }
  }
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