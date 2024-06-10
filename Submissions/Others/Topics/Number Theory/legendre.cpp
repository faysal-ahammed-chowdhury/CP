#include <bits/stdc++.h>
using namespace std;

int legendre(int n, int p) {
  int ex = 0;
  while(n) {
    ex += (n / p);
    n /= p;
  }
  return ex;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}