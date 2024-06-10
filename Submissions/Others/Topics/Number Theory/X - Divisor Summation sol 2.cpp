#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  vector<int> divisors;
  int lim = sqrt(n + 1);
  for(int i = 1; i <= lim; i++) {
    if(n % i == 0) {
      divisors.push_back(i);
      if(i != (n / i)) {
        divisors.push_back(n / i);
      }
    }
  }

  int sum_of_divisor = 0;
  for(auto i: divisors) {
    sum_of_divisor += i;
  }
  cout << sum_of_divisor - n << '\n';
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