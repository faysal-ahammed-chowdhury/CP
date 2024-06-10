#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x % 3]++;
    sum += x;
  }
  if (sum % 3 == 0) {
    cout << 0 << '\n';
    return;
  }

  if (mp.find(sum % 3) != mp.end()) {
    cout << 1 << '\n';
  }
  else {
    cout << 3 - (sum % 3) << '\n';
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