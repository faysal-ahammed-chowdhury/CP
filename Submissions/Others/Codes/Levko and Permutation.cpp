#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int ans[n + 1];
  for (int i = 1; i <= n; i++) {
    ans[i] = i;
  }

  if (n == k) {
    cout << -1 << '\n';
    return 0;
  }

  int should_remove = n - k;
  if (!(should_remove & 1)) {
    should_remove -= 2;
    swap(ans[1], ans[n]);
  }
  else {
    should_remove--;
  }

  for (int i = 2, cnt = 1; cnt <= should_remove; i += 2, cnt += 2) {
    swap(ans[i], ans[i + 1]);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}