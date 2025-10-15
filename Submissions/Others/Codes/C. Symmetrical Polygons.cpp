#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
const ll inf = 1e18;
int n, a[N];

void solve() {
  cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }

  vector<int> v;
  ll ans = 0;
  int side = 0;
  for (auto [x, cnt] : mp) {
    int tmp = cnt;
    if (cnt & 1) {
      v.push_back(x);
      tmp--;
    }
    side += tmp;
    ans += 1ll * x * tmp;
  }

  if (side < 2) {
    cout << 0 << '\n';
    return;
  }

  sort(v.rbegin(), v.rend());
  ll cur = ans;
  if (side == 2) ans = 0;
  for (int i = 0; i < v.size(); i++) {
    int x = 0;
    if (i + 1 < v.size()) x = v[i + 1];
    if (cur + x > v[i]) ans = max(ans, cur + v[i] + x);
  }

  cout << ans << '\n';
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