#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }

  for (int k = 1; k <= n; k++) {
    map<int, int> mp;
    do {
      int sum = 0;
      for (int j = 1; j + k - 1 <= n; j++) {
        int mx = 0;
        for (int i = j; i <= j + k - 1; i++) {
          mx = max(mx, a[i]);
        }
        sum += mx;
      }
      mp[sum]++;
    } while (next_permutation(a + 1, a + n + 1));
    int ans;
    for (auto [sum, cnt] : mp) {
      ans = cnt;
    }
    cout << ans << ' ';
  }

  return 0;
}