#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 3e5 + 9;
pair<int, int> a[N];

void solve() {
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].first = abs(a[i].first);
  }
  sort(a + 1, a + n + 1);

  ll extra = 0, day_cnt = 0;
  for (int i = 1; i <= n; i++) {
    ll mn = min(extra, 1ll * a[i].second);
    extra -= mn;
    a[i].second -= mn;

    if (a[i].second == 0) continue;

    ll days_need = (a[i].second + k - 1) / k;
    ll days_available = a[i].first - day_cnt;

    // cout << days_available << ' ' << days_need << '\n';

    if (days_need > days_available) {
      cout << "NO\n";
      return;
    }

    ll tot_bullet = 1ll * days_need * k;
    extra += tot_bullet - a[i].second;
    a[i].second -= tot_bullet;
    assert(a[i].second <= 0);

    day_cnt += days_need;
  }

  cout << "YES\n";
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