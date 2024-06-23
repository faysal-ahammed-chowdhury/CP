#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int ans = inf;
  for (int k = 1; k + 1 <= n; k++) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (i == k) {
        int x = (s[i] - '0') * 10 + (s[i + 1] - '0');
        v.push_back(x);
        i++;
      }
      else {
        v.push_back(s[i] - '0');
      }
    }
    if (v.size() == 1) {
      cout << v[0] << '\n';
      return;
    }
    int sum = 0;
    bool skip = false;
    for (auto x : v) {
      if (x == 0) {
        cout << 0 << '\n';
        return;
      }
      if (x == 1) {
        skip = true;
        continue;
      }
      sum += x;
    }
    if (skip and sum == 0) sum = 1;
    ans = min(ans, sum);
  }
  cout << ans << '\n';
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