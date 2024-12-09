#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 9, inf = 1e9;
int n, a[N], psum[N];

bool ok(int x) {
  for (int i = 1; i <= n; i++) {
    psum[i] = psum[i - 1] + (a[i] <= x ? 1 : -1);
    // cout << psum[i] << ' ';
  }
  // cout << '\n';
  o_set<pair<int, int>> se;
  ll cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (psum[i] > 0) cnt++;
    int mx = psum[i] - 1;
    cnt += se.order_of_key({mx, inf});
    // cout << se.order_of_key({mx, inf}) << '\n';
    se.insert({psum[i], i});
  }
  // cout << cnt << '\n';
  ll k = (((1ll * n * (n + 1)) / 2) / 2) + 1;
  return k <= cnt;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }
  cout << ans << '\n';
  // cout << ok(20) << '\n';

  return 0;
} 