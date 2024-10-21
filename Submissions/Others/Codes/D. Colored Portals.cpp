#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 1e9;
map<string, vector<int>> mp;
string s[N];

bool common(int i, int j) {
  return ((s[i][0] == s[j][0]) or (s[i][0] == s[j][1]) or (s[i][1] == s[j][0]) or s[i][1] == s[j][1]);
}

int f(int i, int j, string x) {
  // cout << x << '\n';
  auto it1 = upper_bound(mp[x].begin(), mp[x].end(), i);
  int ans1 = inf;
  if (it1 != mp[x].end()) {
    ans1 = abs(*it1 - i) + abs(*it1 - j);
  }

  auto it2 = lower_bound(mp[x].begin(), mp[x].end(), i);
  int ans2 = inf;
  if (it2 != mp[x].begin()) {
    --it2;
    ans2 = abs(*it2 - i) + abs(*it2 - j);
  }

  return min(ans1, ans2);
}

void solve() {
  mp.clear();
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i][0] > s[i][1]) swap(s[i][0], s[i][1]);
    mp[s[i]].push_back(i);
  }
  while (q--) {
    int i, j; cin >> i >> j;
    if (common(i, j)) {
      cout << abs(i - j) << '\n';
    }
    else {
      int ans = inf;
      for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
          string here = "";
          here += s[i][x];
          here += s[j][y];
          if (here[0] > here[1]) swap(here[0], here[1]);
          ans = min(ans, f(i, j, here));
          ans = min(ans, f(j, i, here));
        }
      }
      cout << (ans >= inf ? -1 : ans) << '\n';
    }
  }
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