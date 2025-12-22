#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 33;
string s;
int sz;
ll dp[N][2][2];

ll f(int i, bool is_small, int cur, int k, bool last) {
  if (i == sz) return last == 1;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 1;

  ll &ans = dp[i][is_small][last];
  if (ans != -1) return ans;
  ans = 0;
  for (int x = l; x <= r; x++) {
    if (cur == k and x == 0) continue;
    ans += f(i + 1, (is_small | (x < r)), cur - 1, k, x);
  }
  // cout << i << ' ' << is_small << ' ' << has_started << ' ' << ans << '\n';
  return ans;
}

void get(long long x) {
  if (x < 0) return;
  s = "";
  while (x > 0) {
    char c = (x % 2) + '0';
    s += c;
    x /= 2;
  }
  reverse(s.begin(), s.end());
  sz = s.size();
  memset(dp, -1, sizeof(dp));
}

int cs;
void solve() {
  ll a, k, l, r; cin >> a >> k >> l >> r;
  get(r);
  int ans = 0;
  if (k < sz) ans += f(0, false, sz - 1, k, 0);
  if (l > 1) {
    get(l - 1);
    if (k < sz) ans -= f(0, false, sz - 1, k, 0);
  }
  if (((a & (1 << k)) == 0)) ans = 0;
  cout << (ans % 2 == 0 ? "Even" : "Odd") << '\n';
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