#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100 + 9, MXV = 1e6 + 9;
const ll inf = 1e18;
int spf[MXV];
int n, a[N];
ll dp[N][N][N];

void spf_sieve() {
  for (int i = 2; i < MXV; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < MXV; i++) {
    if (spf[i] == i) {
      for (int j = i; j < MXV; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

ll f(int i, int rem1, int rem2) {
  if (i > n) return (!rem1 and !rem2) ? 0 : inf;
  ll &ans = dp[i][rem1][rem2];
  if (ans != -1) return ans;
  ans = inf;
  ll cost1 = 0, cost2 = 0;
  int x = a[i];
  while (x > 1) {
    int p = spf[x], ex = 0;
    while (x % p == 0) {
      ex++;
      x /= p;
    }
    if (p == 2) cost1 += 1ll * p * ex;
    else cost2 += 1ll * p * ex;
  }
  ans = min(ans, cost1 + f(i + 1, rem1, max(0, rem2 - 1)));
  ans = min(ans, cost2 + f(i + 1, max(0, rem1 - 1), rem2));

  return ans;
}

void solve() {
  int cnt1, cnt2; cin >> n >> cnt1 >> cnt2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  memset(dp, -1, sizeof dp);
  cout << f(1, cnt1, cnt2) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}