#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  if(n & 1) {
    n -= 3;
    int x = (n / 2) + 1;
    cout << x << '\n';
    for(int i = 1; i < x; i++) {
      cout << 2 << ' ';
    }
    cout << "3\n";
  }
  else {
    int x = (n / 2);
    cout << x << '\n';
    for(int i = 1; i <= x; i++) {
      cout << 2 << ' ';
    }
    cout << '\n';
  }

  return 0;
}