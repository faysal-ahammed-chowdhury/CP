#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// O(sqrt(n))
bool is_prime(int n) {
  if (n == 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 7;
  cout << is_prime(n) << '\n';


  return 0;
}