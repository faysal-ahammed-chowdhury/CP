#include <bits/stdc++.h>
using namespace std;

const int N = 80;
int f[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  f[0] = 0, f[1] = 1, f[2] = 1;
  for (int i = 3; i < N; i++) {
    f[i] = f[i - 2] + f[i - 3];
  }

  int n;
  while (cin >> n) {
    cout << f[n] + f[n - 1] << '\n';
  }

  return 0;
}