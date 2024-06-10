#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
  if(n == 1) return false;
  int lim = sqrt(n + 1LL);
  for(int i = 2; i <= lim; i++) {
    if(n % i == 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  if(is_prime(n)) {
    cout << "1\n";
  }
  else if(n % 2 == 0) {
    cout << "2\n";
  }
  else if(is_prime(n - 2)) {
    cout << "2\n";
  }
  else {
    cout << "3\n";
  }

  return 0;
}