#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s = "";
  for (int i = 1; i <= n; i++) {
    char c; cin >> c;
    s += c;
  }
  s += s;

  bool all_same = true;
  for (int i = 1; i < s.size(); i++) {
    all_same &= s[i] == s[i - 1];
  }

  if (all_same) {
    for (int i = 1; i <= n; i++) {
      cout << 0;
    }
    cout << '\n';
    return;
  }

  s = '.' + s;
  int m = n;
  n += n;
  vector<int> ans;
  for (int i = 1; i <= m; i++) {
    int here = 0;
    for (int j = 1; j <= m; j++) {
      int x = (s[j] - '0') ^ (s[i + j - 1] - '0');
      here += (x * (1ll << (m - j)));
    }

    ans.push_back(here);
  }

  sort(ans.rbegin(), ans.rend());
  // cout << ans.size() << '\n';
  int here = ans[0];
  bitset<10> bs(here);
  string t = bs.to_string();
  cout << t.substr(10 - (__lg(here) + 1)) << '\n';
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