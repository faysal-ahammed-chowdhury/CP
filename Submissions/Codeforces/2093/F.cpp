#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 505;
string a[N], b[N][N];
int ok[N];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ok[i] = 0;
  }

  int mx = 0;
  for (int i = 1; i <= m; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      cin >> b[i][j];
      if (b[i][j] == a[j]) {
        cnt++;
        ok[j]++;
      }
    }
    mx = max(mx, cnt);
  }

  for (int i = 1; i <= n; i++) {
    if (ok[i] == 0) {
      cout << -1 << '\n';
      return;
    }
  }

  int rem = n - mx;
  int ans = n;
  ans += (rem * 2);

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