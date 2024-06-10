#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  set<int> se;
  map<int, int> freq;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    se.insert(x);
    freq[x]++;
  }
  vector<int> v;
  int res = (1 << 30) - 1;
  while (v.size() < n) {
    int mx = 0;
    map<int, vector<int>> mp;
    for (auto x : se) {
      mx = max(mx, res & x);
      mp[res & x].push_back(x);
    }
    res &= mx;
    for (auto x : mp[mx]) {
      for (int i = 1; i <= freq[x]; i++) {
        v.push_back(x);
      }
      se.erase(x);
    }
  }

  res = (1 << 30) - 1;
  for (auto x : v) {
    cout << (res &= x) << ' ';
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