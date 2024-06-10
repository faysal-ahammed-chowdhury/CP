#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<char> v;
  for (auto c : s) {
    v.push_back(c);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  map<char, char> mp;
  int x = v.size();
  for (int i = 0, j = x - 1; i <= j; i++, j--) {
    mp[v[i]] = v[j];
    mp[v[j]] = v[i];
  }

  for (auto c : s) {
    cout << mp[c];
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