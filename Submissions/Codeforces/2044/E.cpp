#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

const ll inf = 1e10;
int k, l1, r1, l2, r2;
vector<ll> v;

void f(int pw) {
  i128 ans = 1;
  bool overflow = false;
  for (int i = 1; i <= pw; i++) {
    ans = ans * k;
    if (ans > inf) {
      overflow = true;
      break;
    }
  }
  if (!overflow) v.push_back(ans);
}

bool ok1(int x, int val) {
  return 1ll * x * val >= l2;
}

bool ok2(int x, int val) {
  return 1ll * x * val <= r2;
}

void solve() {
  cin >> k >> l1 >> r1 >> l2 >> r2;

  v.clear();

  for (int i = 0; i <= 30; i++) {
    f(i);
  }

  ll ans = 0;
  for (auto val : v) {
    int l = l1, r = r1, mn_x = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok1(mid, val)) {
        mn_x = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }

    int mx_x = -1;
    l = l1, r = r1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok2(mid, val)) {
        mx_x = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    if (mn_x != -1 and mx_x != -1) ans += mx_x - mn_x + 1;
    // cout << val << ' ' << mn_x << ' ' << mx_x << ' ' << mx_x - mn_x + 1 << '\n';
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