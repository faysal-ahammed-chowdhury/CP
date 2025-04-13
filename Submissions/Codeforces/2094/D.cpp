#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s1, s2; cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  s1 = '@' + s1;
  s2 = '@' + s2;

  vector<int> v1, v2;
  int cnt = 1;
  for (int i = 2; i <= n; i++) {
    if (s1[i] == s1[i - 1]) {
      cnt++;
    }
    else {
      v1.push_back(cnt);
      cnt = 1;
    }
  }
  v1.push_back(cnt);

  cnt = 1;
  for (int i = 2; i <= m; i++) {
    if (s2[i] == s2[i - 1]) {
      cnt++;
    }
    else {
      v2.push_back(cnt);
      cnt = 1;
    }
  }
  v2.push_back(cnt);

  // cout << v1.size() << ' ' << v2.size() << '\n';

  if (v1.size() != v2.size()) {
    cout << "No\n";
    return;
  }

  bool ok = true;
  for (int i = 0; i < v1.size(); i++) {
    ok &= v2[i] >= v1[i] and v2[i] <= v1[i] * 2;
  }

  if (ok and s1[1] == s2[1]) cout << "Yes\n";
  else cout << "No\n";
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