#include <bits/stdc++.h>
using namespace std;

const int N = 55;
long long fibo[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fibo[1] = 1, fibo[2] = 2;
  for (int i = 3; i < N; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  int n;
  while (cin >> n and n) {
    cout << fibo[n] << '\n';
  }

  return 0;
}