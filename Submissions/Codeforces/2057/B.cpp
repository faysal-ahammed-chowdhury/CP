#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }
  vector<int> v;
  v.push_back(0);
  for (auto [x, cnt] : mp) {
    v.push_back(cnt);
  }
  sort(v.begin(), v.end());


  int sz = (int)v.size() - 1, idx = -1;
  for (int i = 1; i <= sz; i++) {
    if (v[i] <= k) {
      k -= v[i];
    }
    else {
      idx = i;
      break;
    }
  }

  if (idx == -1) {
    cout << 1 << '\n';
    return;
  }

  cout << sz - idx + 1 << '\n';
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