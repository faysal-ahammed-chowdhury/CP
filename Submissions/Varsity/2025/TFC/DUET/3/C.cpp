#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  map<int, set<int>> mp;
  while (q--) {
    int t, a, b; cin >> t >> a >> b;
    if (t == 1) {
      mp[a].insert(b);
    }
    else if (t == 2) {
      mp[a].erase(b);
    }
    else {
      if (mp[a].find(b) != mp[a].end() and mp[b].find(a) != mp[b].end()) {
        cout << "Yes\n";
      }
      else cout << "No\n";
    }
  }

  return 0;
}