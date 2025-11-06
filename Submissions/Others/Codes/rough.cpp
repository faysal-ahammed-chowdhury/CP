#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  s = '.' + s;

  map<string, vector<int>> mp;
  for (int i = 1; i < n; i++) {
    mp[s.substr(i, 2)].push_back(i);
  }

  for (auto idx1 : mp["BA"]) {
    for (auto idx2 : mp["AB"]) {
      // cout << idx1 << ' ' << idx2 << '\n';
      if (abs(idx1 - idx2) > 1) {
        cout << "YES\n";
        return 0;
      }
    }
  }

  cout << "NO\n";  

  return 0;
}