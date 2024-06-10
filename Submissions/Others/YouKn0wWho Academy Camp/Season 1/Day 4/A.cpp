#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  set<int> se;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) se.insert(i);
    if(n % i == 0) se.insert(n / i);
  }

  for(auto i: se) {
    cout << i << '\n';
  }

  return 0;
}