#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  string s; cin >> s;
  s  = '.' + s;
  int a[m + 1];
  set<int> ans;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    ans.insert(a[i]);
  }

  sort(a + 1, a + m + 1);
  map<int, int> mp;
  for (int i = m; i >= 1; i--) {
    if (mp.find(a[i] + 1) != mp.end()) {
      mp[a[i]] = mp[a[i] + 1];
    }
    else {
      mp[a[i]] = a[i] + 1;
    }
  }

  // for (auto [x, y] : mp) {
  //   cout << x << ' ' << y << '\n';
  // }

  int cur = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'A') {
      cur++;
      ans.insert(cur);
    }
    else {
      if (ans.find(cur + 1) == ans.end()) {
        cur++;
        ans.insert(cur);
      }
      else {
        int nxt = mp[cur + 1];
        cur = nxt;
        ans.insert(cur);
      }

      if (ans.find(cur + 1) == ans.end()) {
        cur++;
      }
      else {
        int nxt = mp[cur + 1];
        cur = nxt;
      }
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