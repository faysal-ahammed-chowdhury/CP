#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t, cs = 0; cin >> t;
  while(t--) {
    int n, d; cin >> n >> d;
    int num = 0;
    for(int i = 1; i < N; i++) {
      num = (num * 10 + d) % n;
      if(num == 0) {
        cout << "Case " << ++cs << ": ";
        cout << i << '\n';
        break;
      }
    }
  }

  return 0;
}