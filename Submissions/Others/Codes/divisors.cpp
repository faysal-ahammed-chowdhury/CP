#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 12;
  vector<int> divisors;
  for (int i = 1; 1ll * i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i != (n / i)) {
        divisors.push_back(n / i);
      }
    }
  }

  sort(divisors.begin(), divisors.end());
  for (auto x : divisors) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}