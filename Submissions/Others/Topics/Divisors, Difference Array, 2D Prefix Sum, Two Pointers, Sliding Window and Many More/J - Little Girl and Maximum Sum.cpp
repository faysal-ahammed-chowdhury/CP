#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int op[N], a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);

  for (int i = 1; i <= q; i++) {
    int l, r; cin >> l >> r;
    op[l]++;
    op[r + 1]--;
  }

  for (int i = 1; i <= n; i++) {
    op[i] += op[i - 1];
  }
  sort(op + 1, op + 1 + n);

  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += 1ll * a[i] * op[i];
  }
  cout << sum << '\n';

  return 0;
}