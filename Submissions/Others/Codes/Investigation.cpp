#include <bits/stdc++.h>
using namespace std;

const int N = 11, K = 105;
string s;
int sz, k;
int dp[N][2][K][K];

int f(int i, bool is_small, int rem, int sum) {
  if (i == sz) return rem == 0 and sum == 0;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 9;
  int &ans = dp[i][is_small][rem][sum];
  if (ans != -1) return ans;
  ans = 0;
  for (int x = l; x <= r; x++) {
    ans += f(i + 1, (is_small | (x < r)), (rem * 10 + x) % k, (sum + x) % k);
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
  reverse(s.begin(), s.end());
  sz = s.size();
  memset(dp, -1, sizeof(dp));
}

int cs;
void solve() {
  int a, b; cin >> a >> b >> k;
  if (k > 100) {
    cout << "Case " << ++cs << ": " << 0 << '\n';
    return;
  }
  get(a - 1);
  int ans1 = (a == 0) ? 0 : f(0, false, 0, 0);
  get(b);
  int ans2 = f(0, false, 0, 0);
  cout << "Case " << ++cs << ": " << ans2 - ans1 << '\n';
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