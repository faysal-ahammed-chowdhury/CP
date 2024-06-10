#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  bool all_odd = true, all_even = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all_odd &= a[i] & 1;
    all_even &= !(a[i] & 1);
  }
  if (!all_odd and !all_even) {
    sort(a + 1, a + n + 1);
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  return 0;
}