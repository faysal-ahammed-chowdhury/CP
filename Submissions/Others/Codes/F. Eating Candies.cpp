#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long prefix_sum1[n + 1], prefix_sum2[n + 1];
    prefix_sum1[0] = 0, prefix_sum2[0] = 0;
    for(int i = 1; i <= n; i++) {
      prefix_sum1[i] = prefix_sum1[i - 1] + a[i];
    }
    reverse(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
      prefix_sum2[i] = prefix_sum2[i - 1] + a[i];
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      int opposite = n - i;
      if(binary_search(prefix_sum2 + 1, prefix_sum2 + 1 + opposite, prefix_sum1[i])) {
        auto it = lower_bound(prefix_sum2 + 1, prefix_sum2 + 1 + opposite, prefix_sum1[i]);
        ans = max(ans, 1LL * i + (it - prefix_sum2));
      }
    }
    cout << ans << '\n';
  }

  return 0;
}