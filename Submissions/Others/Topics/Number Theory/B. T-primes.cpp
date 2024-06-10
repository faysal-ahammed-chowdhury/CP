#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool is_prime(long long n) {
  if(n == 1) return false;
  int lim = sqrt(n + 1);
  for(int i = 2; i <= lim; i++) {
    if(n % i == 0) return false;
  }
  return true;
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    long long x; cin >> x;
    int sqrt_x = sqrt(x);
    if(1LL * sqrt_x * sqrt_x == x && is_prime(sqrt_x)) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }


  return 0;
}