#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 505;
int n, m, k, arr[N][N], a[N][N];
long long prefix[N][N];

void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }
  int sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c; cin >> c;
      a[i][j] = c - '0';
      if (a[i][j]) sum1 += arr[i][j];
      else sum2 += arr[i][j];
    }
  }
  int diff = abs(sum1 - sum2);
  if (diff == 0) {
    cout << "YES\n";
    return;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
    }
  }

  int gc = 0;
  int tot = k * k;
  for (int x1 = 1; x1 + k - 1 <= n; x1++) {
    for (int y1 = 1; y1 + k - 1 <= m; y1++) {
      int x2 = x1 + k - 1, y2 = y1 + k - 1;
      int cnt1 = (prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1]);
      int cnt0 = (tot - cnt1);
      int d = abs(cnt1 - cnt0);
      gc = __gcd(gc, d);
    }
  }

  if (gc != 0 and diff % gc == 0) cout << "YES\n";
  else cout << "NO\n";
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