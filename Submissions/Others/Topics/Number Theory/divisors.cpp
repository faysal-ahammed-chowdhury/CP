#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 12;
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

  sort(divisors.begin(), divisors.end());
  for(auto i: divisors) {
    cout << i << ' ';
  }
  cout << '\n';
        
  return 0;
}