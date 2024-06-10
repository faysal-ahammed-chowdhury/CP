#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  int old_n = n;
  int sum_of_divisor = 1;
  int lim = sqrt(n + 1);
  for(int i = 2; i <= lim; i++) {
    int power_of_i = 0;
    while(n % i == 0) {
      power_of_i++;
      n /= i;
    }
    sum_of_divisor *= (pow(i, power_of_i + 1) - 1) / (i - 1);
  }
  if(n > 1) {
    int power_of_n = 1;
    sum_of_divisor *= (pow(n, power_of_n + 1) - 1) / (n - 1);
  }

  cout << sum_of_divisor - old_n << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}