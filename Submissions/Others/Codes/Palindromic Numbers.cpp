#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 20;
string s;
int sz;
ll dp[N][2][N][2];

ll f(int i, bool is_small, int start_at, bool ok) {
  if (start_at and i > (start_at + sz) / 2) return ok and start_at;
  if (i > sz) return 0;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 9;

  // cout << "jere: " << l << ' ' << r << '\n';

  ll &ans = dp[i][is_small][start_at][ok];
  if (ans != -1) return ans;
  ans = 0;
  for (int x = l; x <= r; x++) {
    int new_start_at = (start_at ? start_at : x == 0 ? 0 : i);
    bool new_is_small = (is_small | (x < r));
    bool new_ok = ok;
    int op_idx = -1;
    if (new_start_at) {
      int diff = i - new_start_at;
      op_idx = sz - diff;
      int val = s[op_idx] - '0';

      if (x > val) new_ok = false;
      else if (x < val) new_ok = true;
    }

    if (new_is_small) new_ok = true;
    ll cur = f(i + 1, new_is_small, new_start_at, new_ok);
    ans += cur;
    // cout << x << ' ' << new_is_small << ' ' << new_start_at << ' ' << new_ok << ' ' << cur << '\n';
  }
  return ans;
}

void get(long long x) {
  if (x < 0) return;
  s = "";
  while (x > 0) {
    char c = (x % 10) + '0';
    s += c;
    x /= 10;
  }
  s += ".";
  reverse(s.begin(), s.end());
  sz = s.size();
  sz--;
}

int cs;
void solve() {
  ll l, r; cin >> l >> r;
  if (l > r) swap(l, r);
  get(r);
  memset(dp, -1, sizeof(dp));
  ll ans2 = f(1, false, 0, true);
  cout << "Case " << ++cs << ": ";
  if (l == 1) {
    cout << ans2 << '\n';
    return;
  }
  if (l == 0) {
    cout << ++ans2 << '\n';
    return;
  }
  get(l - 1);
  memset(dp, -1, sizeof(dp));
  ll ans1 = f(1, false, 0, true);
  cout << ans2 - ans1 << '\n';
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