#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b; cin >> a >> b;
  long long ans1 = 1;
  for(int i = 1; i <= b; i++) {
    ans1 *= a;
  }
  long long ans2 = 1;
  for(int i = 1; i <= a; i++) {
    ans2 *= b;
  }
  cout << ans1 + ans2 << '\n';


  return 0;
} 