#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }
  if (mp.size() == 1) {
    cout << "Yes\n";
  }
  else if (mp.size() == 2) {
    vector<int> v;
    for (auto x : mp) {
      v.push_back(x.second);
    }
    if (abs(v[0] - v[1]) <= 1) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }
  else {
    cout << "No\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}