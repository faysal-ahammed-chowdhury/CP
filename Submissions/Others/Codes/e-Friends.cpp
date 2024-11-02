#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 13;
int n, k, q;
bool a[N][N];
ll dp[(1 << N) + 5][N][N];

ll f(int mask, int last, int rem) {
  if (__builtin_popcount(mask) == n) {
    return rem >= 0;
  }
  ll &ans = dp[mask][last][rem];
  if (ans != -1) return ans;
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!CHECK(mask, i)) {
      if (last == 0) {
        int new_mask = mask | (1 << i);
        ans += f(new_mask, i, rem);
      }
      else if ((!a[last][i] or (a[last][i] and rem > 0))) {
        int new_mask = mask | (1 << i);
        ans += f(new_mask, i, (rem - a[last][i]));
      }
    }
  }
  return ans;
}

int cs;
void solve() {
  memset(a, false, sizeof a);
  cin >> n >> k >> q;
  for (int i = 1; i <= n; i++) {
    int t; cin >> t;
    for (int j = 1; j <= t; j++) {
      int x; cin >> x;
      a[i][x] = true;
    }
  }

  ll fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }

  cout << "Case " << ++cs << ":\n";
  memset(dp, -1, sizeof dp);
  while (q--) {
    int r; cin >> r;
    if (k == 0) {
      cout << fact << '\n';
      continue;
    }
    int cnt = r / k;
    if (cnt > n) {
      cout << fact << '\n';
    }
    else {
      cout << f(0, 0, cnt) << '\n';
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