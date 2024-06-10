#include <bits/stdc++.h>
using namespace std;

void phi_1_to_n(int n) {
  vector<int> phi(n + 1);
  for (int i = 0; i <= n; i++)
    phi[i] = i;

  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i)
        phi[j] -= phi[j] / i;
    }
  }
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}