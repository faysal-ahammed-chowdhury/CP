#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1073741824;
int number_of_divisors[N];

void sieve() {
  number_of_divisors[1] = 1;
  for (int i = 2; i < N; i++) {
    number_of_divisors[i] += 1;
    for (int j = i; j < N; j += i) {
      number_of_divisors[j]++;
    }
  }
}

int d(int n) {
  return number_of_divisors[n];
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int ans = 0;
  int a, b, c; cin >> a >> b >> c;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        ans += d(i * j * k);
        ans %= mod;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}