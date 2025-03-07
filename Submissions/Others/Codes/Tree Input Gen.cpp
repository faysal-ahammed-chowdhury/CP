#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3, MAX = 100;

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
    cout << n << '\n';
    for (int i = 2; i <= n; i++) {
      cout << get_rand(1, i - 1) << ' ';
    }
    cout << '\n';
  }

  return 0;
}