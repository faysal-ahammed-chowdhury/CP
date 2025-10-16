#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  vector<int> v;
  ll ans1 = 0, ans2 = 0;
  for (auto &[x, cnt] : mp) {
    int tmp = x;
    if (x & 1) {
      v.push_back(cnt);
      tmp--;
    }

    ll here = (1ll * tmp * cnt) / 2;
    ans1 += here;
    ans2 += here;
  }

  sort(v.rbegin(), v.rend());

  for (int i = 0; i < v.size(); i++) {
    if (i % 2 == 0) ans1 += v[i];
    else ans2 += v[i];
  }

  cout << ans1 << ' ' << ans2 << '\n';
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