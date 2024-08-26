#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  map<char, int> mp;
  for (auto c : s) {
    mp[c]++;
  }
  if (mp.size() == 1) {
    cout << s << '\n';
    return;
  }
  vector<pair<int, char>> v;
  for (auto [c, cnt] : mp) {
    v.push_back({cnt, c});
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < v.size(); i++) {
    while (v[i].first > 0) {
      v[i].first--;
      cout << v[i].second;
      for (int j = i + 1; j < v.size(); j++) {
        if (v[j].first > 0) {
          v[j].first--;
          cout << v[j].second;
        }
      }
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}