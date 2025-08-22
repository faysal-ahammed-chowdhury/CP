#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, inf = 2e9;
int a[N], b[N];
vector<pair<int, bool>> all;
ll pref1[N], pref2[N], pref[N + N];
int cnt [N + N];

void solve() {
  all.clear();
  all.push_back({inf, 0});
  int n, m, q; cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all.push_back({a[i], 1});
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    all.push_back({b[i], 0});
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  reverse(b + 1, b + m + 1);
  sort(all.rbegin(), all.rend());

  for (int i = 1; i <= n; i++) {
    pref1[i] = pref1[i - 1] + a[i];
  }
  for (int i = 1; i <= m; i++) {
    pref2[i] = pref2[i - 1] + b[i];
  }

  int n_plus_m = n + m;
  for (int i = 1; i <= n_plus_m; i++) {
    cnt[i] = cnt[i - 1] + all[i].second;
    pref[i] = pref[i - 1] + all[i].first;
  }

  while (q--) {
    int x, y, z; cin >> x >> y >> z;
    int xx = cnt[z];
    int yy = z - xx;

    // cout << xx << ' ' << yy << '\n';

    if (xx <= x and yy <= y) {
      cout << pref[z] << '\n';
    }
    else if (xx > x) {
      cout << pref1[x] + pref2[z - x] << '\n';
    }
    else {
      cout << pref1[z - y] + pref2[y] << '\n';
    }
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