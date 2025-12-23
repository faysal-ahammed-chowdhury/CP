#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5, MAX = 10;

// NEVER use rand() function because rand() will always generate same random values even if you run the same code multiple times
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); // using current time as seed, so it will always generate different random values if you run this code multiple times
long long get_rand(long long l, long long r) { // random number from l to r
  assert(l <= r);
  return l + rnd() % (r - l + 1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = get_rand(1, 1);
  // cout << t << '\n';
  while (t--) {
    int n = get_rand(2, N);
    int q = get_rand(1, N);
    cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) {
      cout << get_rand(1, MAX) << ' ';
    }
    cout << '\n';

    while (q--) {
      int type = get_rand(1, 2);
      int i = get_rand(1, n);
      int k = get_rand(1, n);
      cout << type << ' ' << i << ' ';
      if (type == 1) cout << k << '\n';
      else cout << '\n';
    }
  }

  return 0;
}