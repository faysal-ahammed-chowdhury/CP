#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  long long sum = 0;
  for (int i = 1; i < k; i++) {
    sum += a[i];
  }

  for (int i = k; i <= n; i++) {
    if (sum > a[i]) {
      cout << "Yes\n";
      return 0;
    }
    sum += a[i];
    sum -= a[i - k + 1];
  }
  cout << "No\n";
  
  return 0;
}