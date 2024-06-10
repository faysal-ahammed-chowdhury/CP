#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;

  if (k == 1) {
    cout << "Yes\n";
    return 0;
  } 

  if (n == 2 and (k <= n)) {
    cout << "Yes\n";
    return 0;
  }

  if (k >= n) {
    cout << "No\n";
    return 0;
  }

  if (n % 2 == 0 and k == 2) {
    cout << "Yes\n";
    return 0;
  }

  if (n == 4 and k == 3) {
    cout << "Yes\n";
    return 0;
  }

  cout << "No\n";

  return 0;
}