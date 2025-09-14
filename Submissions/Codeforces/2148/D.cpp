#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  vector<int> odd;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x & 1) odd.push_back(x);
    else sum += x;
  }

  if (odd.size() == 0) {
    cout << 0 << '\n';
    return;
  }

  sort(odd.rbegin(), odd.rend());

  int cnt = (odd.size() + 1) / 2;
  for (int i = 0; i < cnt; i++) {
    sum += odd[i];
  }

  cout << sum << '\n';
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