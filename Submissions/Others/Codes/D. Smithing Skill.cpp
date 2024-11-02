#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int A = 0;
  int a[n + 1], b[n + 1], c[m + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    A = max(A, a[i]);
  }
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= m; i++) cin >> c[i];
  int best[A + 1];
  fill(best, best + A + 1, inf);
  for (int i = 1; i <= n; i++) best[a[i]] = min(best[a[i]], a[i] - b[i]);
  for (int i = 1; i <= A; i++) best[i] = min(best[i], best[i - 1]);

  long long ans[A + 1];
  memset(ans, 0, sizeof ans);
  for (int x = 1; x <= A; x++) {
    if (x >= best[x]) {
      ans[x] = 2 + ans[x - best[x]];
    }
  }

  long long final_ans = 0;
  for (int i = 1; i <= m; i++) {
    int x = c[i];
    if (x > A) {
      long long k = (x - A + best[A] - 1) / best[A];
      final_ans += 2ll * k;
      x -= k * best[A];
    }
    final_ans += ans[x];
  }
  cout << final_ans << '\n';

  return 0;
}