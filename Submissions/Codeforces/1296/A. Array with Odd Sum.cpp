#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x % 2]++;
  }
  if (mp.find(0) != mp.end() and mp.find(1) != mp.end()) {
    cout << "YES\n";
  }
  else if (mp.find(1) != mp.end() and mp[1] % 2 == 1) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
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