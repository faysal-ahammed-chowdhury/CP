#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b; cin >> a >> b;
  if (a > 0) {
    cout << "Positive\n";
  }
  else if (a <= 0 and b >= 0) {
    cout << "Zero\n";
  }
  else {
    int len = abs(a) - abs(b) + 1;
    if (len & 1) {
      cout << "Negative\n";
    }
    else {
      cout << "Positive\n";
    }
  }

  return 0;
}