#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N], ans[N];
pair<int, int> op[N];

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);

  for (int i = 0; i <= n; i++) {
    op[i].first = 0;
  }

  for (int i = 1; i <= q; i++) {
    int l, r; cin >> l >> r;
    op[l].first++;
    op[r + 1].first--;
  }

  for (int i = 1; i <= n; i++) {
    op[i].first += op[i - 1].first;
    op[i].second = i;
  }
  sort(op + 1, op + 1 + n);

  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += 1ll * a[i] * op[i].first;
    ans[op[i].second] = a[i];
  }
  cout << sum << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}