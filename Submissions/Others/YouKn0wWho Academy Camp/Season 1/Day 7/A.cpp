#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int s, w; cin >> s >> w;
  if (w >= s) {
    cout << "unsafe\n";
  } 
  else {
    cout << "safe\n";
  }

  return 0;
}