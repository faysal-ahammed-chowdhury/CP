#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n, q; cin >> n >> q;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, int> mp;
  for (int i = 1; i < n; i++) {
    int x = i * (n - i + 1) - 1;
    mp[x]++;
  }
  mp[n - 1]++;
  for (int i = 1; i < n; i++) {
    int x = i * (n - i);
    int cnt = a[i + 1] - a[i] - 1;
    if (cnt > 0) mp[x] += cnt;
  }
  while (q--) {
    int k; cin >> k;
    if (mp.find(k) == mp.end()) {
      cout << 0 << ' ';
    }
    else {
      cout << mp[k] << ' ';
    }
  }
  cout << '\n';
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