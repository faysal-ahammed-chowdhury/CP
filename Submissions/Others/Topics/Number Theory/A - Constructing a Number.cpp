#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      while(x > 0) {
        sum += x % 10;
        x /= 10;
      }
    }
    if(sum % 3 == 0) {
      cout << "Yes\n";
  }
    else {
      cout << "No\n";
    }
  }

  return 0;
}