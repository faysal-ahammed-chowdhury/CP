#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
  if (n == 1) return false;
  int lim = sqrt(n + 1);
  for (int i = 2; i <= lim; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve() {
  int n; cin >> n;
  if (n == 1 or n == 3) {
    cout << "First\n";
  }
  else if (n == 2 or n == 9) {
    cout << "Second\n";
  }
  else if (n % 2 == 0) {
    cout << "First\n";
  }
  else {
    if (is_prime(n)) {
      cout << "Second\n";
    }
    else {
      cout << "First\n";
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}