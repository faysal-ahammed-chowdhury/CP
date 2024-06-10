#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
  if (n == 2) return true;
  if (n == 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n; cin >> n;
  cout << (is_prime(n) ? "Yes\n" : "No\n");

  return 0;
}