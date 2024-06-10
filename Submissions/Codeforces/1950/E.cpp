#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  vector<int> divs;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i != n / i) {
        divs.push_back(n / i);
      }
    }
  }
  sort(divs.begin(), divs.end());
  for (auto len : divs) {
    set<string> se;
    map<string, int> mp;
    for (int i = 1; i <= n; i += len) {
      string x = s.substr(i, len);
      se.insert(x);
      mp[x]++;
    }
    if (se.size() == 1) {
      cout << len << '\n';
      return;
    }
    else if (se.size() == 2) {
      bool ok = false;
      for (auto [str, cnt] : mp) {
        ok |= cnt == 1;
      }

      if (!ok) continue;

      string s1 = *se.begin();
      se.erase(se.begin());
      string s2 = *se.begin();
      int mis = 0;
      for (int j = 0; j < len; j++) {
        mis += s1[j] != s2[j];
      }
      if (mis <= 1) {
        cout << len << '\n';
        return;
      }
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