#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  map<string, int> mp;
  for (int i = 1; i <= m; i++) {
    string s; cin >> s;
    mp[s]++;
  }
  vector<int> v;
  for (auto [s, cnt] : mp) {
    v.push_back(cnt);
  }
  sort(v.rbegin(), v.rend());
  int sz = v.size();

  long long ans1 = 0, ans2 = 0;
  for (int i = 0; i < v.size(); i++) {
    ans1 += 1ll * v[i] * a[i + 1];
  }
  reverse(a + 1, a + n + 1);
  for (int i = 0; i < v.size(); i++) {
    ans2 += 1ll * v[i] * a[i + 1];
  }

  cout << ans1 << ' ' << ans2 << '\n';

  return 0;
}