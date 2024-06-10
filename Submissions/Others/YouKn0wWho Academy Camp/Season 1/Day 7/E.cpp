#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
  if (n == 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b; cin >> a >> b;
  int c, d; cin >> c >> d;

  for (int i = a; i <= b; i++) {
    bool ans = true;
    for (int j = c; j <= d; j++) {
      ans &= !is_prime(i + j);
    }
    if (ans) {
      cout << "Takahashi\n";
      return 0;
    }
  }

  cout << "Aoki\n";

  return 0;
}