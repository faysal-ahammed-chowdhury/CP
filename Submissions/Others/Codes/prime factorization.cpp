#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 24;
  vector<int> prime_factors;
  int lim = sqrt(n + 1);
  for (int i = 2; i <= lim; i++) {
    while (n % i == 0) {
      prime_factors.push_back(i);
      n /= i;
    }
  }
  if (n > 1) prime_factors.push_back(n);

  sort(prime_factors.begin(), prime_factors.end());
  for (auto i : prime_factors) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}