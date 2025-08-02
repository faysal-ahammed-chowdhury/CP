#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int len = 0;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    len += s.size();
    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '0') cnt++;
      else break;
    }

    if (cnt > 0) v.push_back(cnt);
  }

  sort(v.rbegin(), v.rend());

  for (int i = 0; i < v.size(); i += 2) {
    len -= v[i];
  }

  if (len > m) {
    cout << "Sasha\n";
  }
  else {
    cout << "Anna\n";
  }
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