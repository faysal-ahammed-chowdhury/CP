#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 1e9;
int a[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
 
  int sum = 0, ans = inf, idx = -1;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    if (i >= k) {
      if (sum < ans) {
        ans = sum;
        idx = i - k + 1;
      }
      sum -= a[i - k + 1];
    }
  }

  cout << idx << '\n';

  return 0;
}