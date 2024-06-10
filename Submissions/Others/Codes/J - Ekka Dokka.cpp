#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    unsigned long long w; cin >> w;
    cout << "Case " << ++cs << ": ";
    if(w & 1) {
      cout << "Impossible\n";
      continue;
    }
    unsigned long long m = 1, x = w;
    while(x % 2 == 0) {
      m *= 2;
      x /= 2;
    }

    unsigned long long n = w / m;
    cout << n << ' ' << m << '\n'; 
  }

  return 0;
}