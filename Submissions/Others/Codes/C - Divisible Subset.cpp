#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    a[i] %= n;
  }
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      cout << i << '\n';
      for (int idx = 1; idx <= i; idx++) {
        cout << idx << ' ';
      }
      cout << '\n';
      return;
    }
    if (mp.find(a[i]) != mp.end()) {
      int len = i - mp[a[i]];
      cout << len << '\n';
      for (int idx = mp[a[i]] + 1; idx <= i; idx++) {
        cout << idx << ' ';
      }
      cout << '\n';
      return;
    }
    mp[a[i]] = i;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}