#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 10005;

ll nC4(int n) {
  return (1ll * n * (n - 1) * (n - 2) * (n - 3)) / 24;
}

int cs;
void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int div_cnt[N];
  memset(div_cnt, 0, sizeof(div_cnt));
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        div_cnt[i]++;
        if (i != (x / i)) {
          div_cnt[x / i]++;
        }
      }
    }
  }

  // exclusion dp (template code)
  ll f[N], g[N];
  for (int i = N - 1; i >= 1; i--) {
    f[i] = nC4(div_cnt[i]);
    g[i] = f[i];
    for (int j = i + i; j < N; j += i) {
      g[i] -= g[j];
    }
  }

  cout << "Case " << ++cs << ": " << g[1] << '\n';
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