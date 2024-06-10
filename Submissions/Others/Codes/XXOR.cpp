#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 9, K = 42;
int n, on_bit[K];
ll a[N], k;

bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }

string s;
int sz;
ll dp[K][2];

ll fun(int i, bool is_small) {
  if (i < 0) return 0;
  int l = 0, r = s[i] - '0';
  if (is_small) r = 1;

  ll &ans = dp[i][is_small];
  if (ans != -1) return ans;
  ans = (1ll * on_bit[i] * (1ll << i)) + fun(i - 1, r == 1 ? true : is_small);
  if (r == 1) {
    ans = max(ans, (1ll * (n - on_bit[i]) * (1ll << i)) + fun(i - 1, is_small));
  }
  return ans;
}

void get(ll x) {
  bitset<K - 1> bs(x);
  s = bs.to_string();
  reverse(s.begin(), s.end());
  sz = s.size();
  memset(dp, -1, sizeof(dp));
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int k = 0; k <= 40; k++) {
    for (int i = 1; i <= n; i++) {
      if (CHECK(a[i], k)) {
        on_bit[k]++;
      }
    }
  }

  get(k);
  cout << fun(sz - 1, 0) << '\n';

  return 0;
}