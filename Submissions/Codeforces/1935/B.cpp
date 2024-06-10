#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  bool all_zero = true, no_zero = true;
  set<int> missing_numbers;
  for (int i = 0; i <= n + 10; i++) {
    missing_numbers.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all_zero &= a[i] == 0;
    no_zero &= a[i] != 0;
    missing_numbers.erase(a[i]);
  }

  if (all_zero or no_zero) {
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
      cout << i << ' ' << i << '\n';
    }
    return;
  }

  int mex = *missing_numbers.begin();

  set<int> missing_numbers1, missing_numbers2;
  for (int i = 0; i <= n + 10; i++) {
    missing_numbers1.insert(i);
    missing_numbers2.insert(i);
  }

  int mid = - 1;
  for (int i = 1; i < n; i++) {
    missing_numbers1.erase(a[i]);
    if (*missing_numbers1.begin() == mex) {
      mid = i;
      break;
    }
  }

  if (mid == -1) {
    cout << -1 << '\n';
    return;
  }

  for (int  i = mid + 1; i <= n; i++) {
    missing_numbers2.erase(a[i]);
  }

  if (*missing_numbers1.begin() != *missing_numbers2.begin()) {
    cout << -1 << '\n';
    return;
  }

  cout << 2 << '\n';
  cout << 1 << ' ' << mid << '\n';
  cout << mid + 1 << ' ' << n << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}