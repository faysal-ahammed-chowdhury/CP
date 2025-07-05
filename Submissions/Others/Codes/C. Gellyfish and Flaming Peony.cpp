#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5005, inf = 1e9;
int n, a[N], dp[N][N];
int gc; 

int f(int i, int cur_gc) {
  if (i > n) {
    return (cur_gc == gc ? 0 : inf);
  }
  int &ans = dp[i][cur_gc];
  if (ans != -1) return ans;
  ans = f(i + 1, cur_gc);
  ans = min(ans, 1 + f(i + 1, __gcd(cur_gc, a[i])));
  return ans;
}

void solve() {
  cin >> n;
  gc = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    gc = __gcd(gc, a[i]);
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += gc == a[i];
  }

  if (cnt > 0) {
    cout << n - cnt << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 5000; j++) {
      dp[i][j] = -1;
    }
  }
  cout << f(1, 0) + n - 2 << '\n';
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