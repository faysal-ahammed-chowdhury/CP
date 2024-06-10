#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int x1, y1; cin >> x1 >> y1;
  int x2, y2; cin >> x2 >> y2;
  int x3, y3; cin >> x3 >> y3;

  if(((y2 >= y1 && y3 >= y1) || (y2 <= y1 && y3 <= y1)) && ((x2 <= x1 && x3 >= x1) || (x2 >= x1 && x3 <= x1))) {
    if(y2 >= y1 && y3 >= y1) {
      cout << abs(min(abs(y2), abs(y3)) - abs(y1)) + 1  << '\n';
    }
    else {
      cout << abs(max(abs(y2), abs(y3)) - abs(y1)) + 1  << '\n';
    }
    return;
  }

  if(((x2 >= x1 && x3 >= x1) || (x2 <= x1 && x3 <= x1)) && ((y2 <= y1 && y3 >= y1) || (y2 >= y1 && y3 <= y1))) {
    if(x2 >= x1 && x3 >= x1) {
      cout << abs(min(abs(x2), abs(x3)) - abs(x1)) + 1  << '\n';
    }
    else {
      cout << abs(max(abs(x2), abs(x3)) - abs(x1)) + 1  << '\n';
    }
    return;
  }

  if(((x2 >= x1 && x3 >= x1) || (x2 <= x1 && x3 <= x1)) && ((y2 >= y1 && y3 >= y1))) {
    int x = min(abs(y2), abs(y3)) - abs(y1) + 1;
    x += min(abs(x2), abs(x3)) - abs(x1);
    cout << x << '\n';
    return;
  }
  cout << 1 << '\n';
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