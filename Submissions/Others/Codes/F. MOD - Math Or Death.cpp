#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b; cin >> a >> b;
  if(a == b) {
    cout << "infinity\n";
  }
  else {
    int x = a - b;
    vector<int> divisors;
    int lim = sqrt(x + 1);
    for(int i = 1; i <= lim; i++) {
      if(x % i == 0) {
        divisors.push_back(i);
        if(i != (x / i)) {
          divisors.push_back(x / i);
        }
      }
    }
    int ans = 0;
    for(auto i: divisors) {
      if(a % i == b) {
        ans++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}