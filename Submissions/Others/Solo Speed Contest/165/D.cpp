#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + n + 1);
  int low = sum / n;
  int high = low;
  int ans = 0;
  if (low * n < sum) high++;
  int cnt = sum % n;
  for (int i = 1; i <= n - cnt; i++) {
    ans += abs(low - a[i]);
  }
  for (int i = n, j = 1; i >= 1 and j <= cnt; i--, j++) {
    ans += abs(a[i] - high);
  }
  cout << ans / 2 << '\n';

  return 0;
}