#include <bits/stdc++.h>
using namespace std;

long long C(int n, int k) {
  long long ans = 1;
  for (int i = 1; i <= k; i++) {
    ans *= (n - i + 1);
    ans /= i;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  long long ans = 1;
  if (2 <= k) ans += C(n, 2);
  if (3 <= k) ans += C(n, 3) * 2;
  if (4 <= k) ans += C(n, 4) * 9;

  cout << ans << '\n';

  return 0;
}