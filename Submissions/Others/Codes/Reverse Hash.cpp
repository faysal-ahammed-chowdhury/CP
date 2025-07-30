#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
int n, m, b, h, pw[N];
bool dp[N][N], vis[N][N];

bool f(int i, int hash) {
  if (i > n) return hash == h;
  if (vis[i][hash]) return dp[i][hash];
  vis[i][hash] = true;
  bool ans = f(i + 1, hash);
  int new_hash = (hash + pw[i]) % m;
  ans |= f(i + 1, new_hash);
  return dp[i][hash] = ans;
}

void print(int i, int hash) {
  if (i > n) return;
  bool ans1 = f(i + 1, hash);
  if (ans1) {
    cout << 0;
    print(i + 1, hash);
    return;
  }
  int new_hash = (hash + pw[i]) % m;
  bool ans2 = f(i + 1, new_hash);
  cout << 1;
  print(i + 1, new_hash);
}

void solve() {
  cin >> n >> m >> b >> h;
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = 1ll * pw[i - 1] * b % m;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      vis[i][j] = 0;
    }
  }
  bool ans = f(1, 0);
  if (ans) {
    print(1, 0);
    cout << '\n';
  }
  else cout << -1 << '\n';
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