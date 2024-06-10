#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int x, y; cin >> x >> y;
  double xpowy = y * log(x);
  double ypowx = x * log(y);
  if(xpowy == ypowx) {
    cout << "=\n";
  }
  else if(xpowy > ypowx) {
    cout << ">\n";
  }
  else {
    cout << "<\n";
  }
        
  return 0;
}