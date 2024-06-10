#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 65;
ll C[N][N];

void prec() {
  for (int i = 0; i < N; i++) {
    C[i][i] = 1;
    for (int j = 0; j < i; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int a, b; ll k; cin >> a >> b >> k;
  while (a or b) {
    ll possible = C[a + b - 1][b];
    if (k <= possible) {
      cout << 'a';
      a--;
    }
    else {
      cout << 'b';
      k -= possible, b--;
    }
  }
  cout << '\n';

  return 0;
}