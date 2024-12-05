#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 10, MAX = 100;

// NEVER use rand() function because rand() will always generate same random values even if you run the same code multiple times
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); // using current time as seed, so it will always generate different random values if you run this code multiple times
long long get_rand(long long l, long long r) { // random number from l to r
  assert(l <= r);
  return l + rnd() % (r - l + 1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = get_rand(1, 2);
  cout << t << '\n';
  while (t--) {
    int n = get_rand(1, N);
    int q = get_rand(1, N);
    cout << n << ' ' << q << '\n';
    for (int i = 1; i <= n; i++) {
      cout << get_rand(1, MAX) << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= q; i++) {
      int l = get_rand(1, n);
      int r = get_rand(1, n);
      cout << min(l, r) << ' ' << max(l, r) << '\n';
    }
  }

  return 0;
}