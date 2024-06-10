#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int inf = 2e9;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 5], b[n + 5][n + 5];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      b[i][j] = min(a[i], a[j]);
    }
  }
  int left[k + 6], right[k + 6], top[k + 6], bottom[k + 6];
  fill(left, left + k + 1, inf);
  fill(top, top + k + 1, inf);
  fill(right, right + k + 1, -inf);
  fill(bottom, bottom + k + 1, -inf);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      left[b[i][j]] = min(left[b[i][j]], j);
      right[b[i][j]] = max(right[b[i][j]], j);
      top[b[i][j]] = min(top[b[i][j]], i);
      bottom[b[i][j]] = max(bottom[b[i][j]], i);
    }
  }

  for(int i = 1; i <= k; i++) {
    long long ans = 1ll * (right[i] - left[i] + 1) + (bottom[i] - top[i] + 1);
    if(top[i] == inf) {
      cout << 0 << ' ';
    }
    else {
      cout << ans << ' ';
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}