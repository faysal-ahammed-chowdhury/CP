#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; ll k; cin >> n >> k;
  vector<int> v;
  map<int, ll> mp;
  for (int i = 1; i <= n; i++) {
    int a, b; cin >> a >> b;
    mp[a] += b;
    v.push_back(a);
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  ll cnt = 0;
  for (int i = 0; i < v.size(); i++) {
    int x = v[i];
    cnt += mp[x];
    if (k <= cnt) {
      cout << x << '\n';
      return 0;
    }
  }

  return 0;
}