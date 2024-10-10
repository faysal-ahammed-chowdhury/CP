#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  if (n == k) {
    cout << -1 << '\n';
    return 0;
  } 
  
  int a[n + 1];
  a[1] = 1;
  for (int i = 1; i <= k; i++) {
    a[i + 1] = i + 1;
  }

  int rem = n - 1 - k;
  int idx = 2 + k;
  if (rem & 1) {
    a[idx] = 1;
    a[1] = idx;
    idx++;
  }
  for (int i = idx; i + 1 <= n; i += 2) {
    a[i] = i + 1;
    a[i + 1] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  return 0;
}