#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int inf = 1e9;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  map<int, vector<int>> list;
  map<int, int> mp2[n + 5];
  for(int i = 0; i < n; i++) {
    int k; cin >> k;
    for(int j = 0; j < k; j++) {
      int x; cin >> x;
      mp[x]++;
      mp2[i][x]++;
      list[x].push_back(i);
    }
  }

  int total = (int) mp.size();

  int ans = inf;
  for(int i = 1; i <= 50; i++) {
    if(mp.find(i) == mp.end()) continue;
    int cut = 0;
    map<int, int> remove;
    for(auto j: list[i]) {
      for(auto k: mp2[j]) {
        remove[k.first] += k.second;
      }
    }
    for(auto j: remove) {
      if(j.second == mp[j.first]) {
        cut++;
      }
    }
    ans = min(ans, cut);
  }

  cout << total - ans << '\n';
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