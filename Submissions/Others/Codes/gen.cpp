#include<bits/stdc++.h>
using namespace std;

const int N = 8;

// NEVER use rand() function because rand() will always generate same random values even if you run the same code multiple times
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); // using current time as seed, so it will always generate different random values if you run this code multiple times
long long get_rand(long long l, long long r) { // random number from l to r
  assert(l <= r);
  return l + rnd() % (r - l + 1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cout << 1 << '\n';
  int a = get_rand(1, N);
  int b = get_rand(1, N);
  int l = get_rand(1, N * N);
  cout << a << ' ' << b << ' ' << l << '\n';

  return 0;
}