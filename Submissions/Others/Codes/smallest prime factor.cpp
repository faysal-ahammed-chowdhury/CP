#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 11;
  int lim = sqrt(n + 1);
  for (int i = 2; i <= lim; i++) {
    while (n % i == 0) {
      cout << i << '\n';
      return 0;
    }
  }
  if (n > 1) cout << n << '\n';



  return 0;
}