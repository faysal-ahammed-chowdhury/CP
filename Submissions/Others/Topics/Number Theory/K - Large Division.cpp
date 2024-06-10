#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    string a; int b; cin >> a >> b;
    int num = 0, n = a.size();
    int i = a[0] == '-' ? 1 : 0;
    for(; i < n; i++) {
      num = (1LL * num * 10 + (a[i] - '0')) % b;
    }
    cout << "Case " << ++cs << ": ";
    if(num == 0) {
      cout << "divisible\n";
    }
    else {
      cout << "not divisible\n";
    }
  }

  return 0;
}