#include <bits/stdc++.h>
using namespace std;

int bin_to_int(int n) {
  int ans = 0, pos = 0;
  while(n > 0) {
    int last_ligit = n % 10;
    n /= 10;
    if(last_ligit == 1) {
      ans += (1 << pos);
    }
    pos++;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    char ch;
    int a, b, c, d; cin >> a >> ch >> b >> ch >> c >> ch >> d;
    int a1, b1, c1, d1; cin >> a1 >> ch >> b1 >> ch >> c1 >> ch >> d1;

    a1 = bin_to_int(a1);
    b1 = bin_to_int(b1);
    c1 = bin_to_int(c1);
    d1 = bin_to_int(d1);

    cout << "Case " << ++cs << ": ";
    if(a == a1 && b == b1 && c == c1 && d == d1) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }

  return 0;
}