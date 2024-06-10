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

  int a, b; cin >> a >> b;
  if(a == 1 && b == 2) {
    cout << "Yes\n";
  }
  else if(a == 2 && b == 3) {
    cout << "Yes\n";
  }
  else if(a == 4 && b == 5) {
    cout << "Yes\n";
  }
  else if(a == 5 && b == 6) {
    cout << "Yes\n";
  }
  else if(a == 7 && b == 8) {
    cout << "Yes\n";
  }
  else if(a == 8 && b == 9) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }
        
  return 0;
}