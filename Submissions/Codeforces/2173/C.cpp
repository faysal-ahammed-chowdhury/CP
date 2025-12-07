#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a.push_back(x);
    mp[x]++;
  }
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());

  vector<int> ans;
  set<int> se;
  for (auto x : a) {
    if (se.find(x) != se.end()) continue;
    int val = x;
    ans.push_back(x);
    while (true) {
      if (mp.find(val) == mp.end()) {
        if (val <= k) {
          cout << -1 << '\n';
          return;
        }
        break;
      }
      se.insert(val);
      val += x;
    }
  }

  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << ' ';
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