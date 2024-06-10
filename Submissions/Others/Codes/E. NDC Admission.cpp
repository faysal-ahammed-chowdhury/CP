#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 9;
int a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  
  vector<pair<int, int>> v, pairs;
  while (m--) {
    int l, r; cin >> l >> r;
    v.push_back(make_pair(l, r));
  }
  int sz = v.size();

  ll ans = 0;
  map<int, int> mp, mp2;
  for (int i = 1; i <= n; i++) {
    int need = k - a[i];
    ans += mp[need];
    mp[a[i]]++;
  }

  if (sz == 0) {
    cout << ans << '\n';
    return 0;
  }

  sort(v.begin(), v.end());
  pairs.push_back(v[0]);
  int last = v[0].second;
  for (int i = 1; i < sz; i++) {
    if (v[i].second > last) {
      pairs.push_back(v[i]);
    }
  }

  int i = 0, j = 0;
  for (auto [l, r] : pairs) {
    while (i < l) {
      if (mp2[a[i]] != 0) mp2[a[i]]--;
      i++;
    }
    j = max(j, i);
    while (j <= r) {
      int need = k - a[j];
      ans -= mp2[need];
      mp2[a[j]]++;
      j++;
    }
  }

  cout << ans << '\n';
  
  return 0;
}