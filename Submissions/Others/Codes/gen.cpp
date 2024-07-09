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

  int n = get_rand(2, N);
  int m = get_rand(N, N + 50);
  int q = get_rand(30, 500);
  cout << n << ' ' << m << ' ' << q  << '\n';
  while (m--) {
    cout << get_rand(1, n) << ' ' << get_rand(1, n) << '\n';
  }
  for (int i = 1; i <= n; i++) {
    cout << get_rand(0, 500) << ' ';
  }
  cout << '\n';

  string s[3] = {"Q", "AC", "AS"};
  while (q--) {
    int idx = get_rand(0, 2);
    if (s[idx] == "Q") {
      cout << "Q\n";
      continue;
    }
    cout << s[idx] << ' ' << get_rand(-500, 500) << ' ' << get_rand(1, n) << '\n';
  }
  
  
  return 0;
}