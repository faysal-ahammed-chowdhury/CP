#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n; cin >> n;
  int x = sqrt(n);

  int last = 1, lim = sqrt(x + 1);
  for(int i = 2; i <= lim; i++) {
    while(x % i == 0) {
      last = i;
      x /= i;
    }
  }
  if(x > 1) last = x;
  cout << last << '\n';

  return 0;
}