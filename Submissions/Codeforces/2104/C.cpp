#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  vector<int> v1, v2;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'A') v1.push_back(i);
    else v2.push_back(i);
  }
  bool bob = true;
  for (auto x : v1) {
    auto it = lower_bound(v2.begin(), v2.end(), x);
    if (x == n) it = lower_bound(v2.begin(), v2.end(), 1);
    if (it == v2.end()) {
      bob = false; 
      break;
    }
    if (x == 1) {
      bob &= (*it > x) and (*it < n);
    }
    else if (x == n) bob &= *it == 1;
    else bob &= *it > x;
  }
  if (bob) cout << "Bob\n";
  else cout << "Alice\n";
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