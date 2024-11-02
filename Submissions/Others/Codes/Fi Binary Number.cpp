#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 47;
const ll MAX = 10000000000000;
string s;
int sz, n;
int dp[N][2][2];

int f(int i, bool is_small, bool last_one) {
  if (i == sz) return 1;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 1;
  int &ans = dp[i][is_small][last_one];
  if (ans != -1) return ans;
  ans = 0;
  for (int x = l; x <= r; x++) {
    if (last_one and x == 1) continue;
    ans += f(i + 1, (is_small | (x < r)), (x == 1));
  }
  return ans;
}

void get(ll x) {
  if (x < 0) return;
  bitset<N> bs(x);
  s = bs.to_string();  
  sz = s.size();
  memset(dp, -1, sizeof(dp));
}

bool ok(ll x) {
  get(x);
  return ((f(0, 0, 0) - 1) >= n);
}

int cs;
void solve() {
  cin >> n;
  ll l = 1, r = MAX, ans = -1; 
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  bitset<N> bs(ans);
  s = bs.to_string();
  bool has_started = false;
  cout << "Case " << ++cs << ": ";
  for (auto c : s) {
    if (c == '1') has_started = true;
    if (has_started) cout << c;
  }
  cout << '\n';
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