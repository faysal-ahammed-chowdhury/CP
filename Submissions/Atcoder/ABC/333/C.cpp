#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<long long> v;
  v.push_back(0);
  v.push_back(3);

  for (int i = 1; i <= 3; i++) {
    v.push_back(i * 10 + 3);
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = i; j <= 3; j++) {
      v.push_back(i * 100 + j * 10 + 3);
    }
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = i; j <= 3; j++) {
      for (int k = j; k <= 3; k++) {
        v.push_back(i * 1000 + j * 100 + k * 10 + 3);
      }
    }
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = i; j <= 3; j++) {
      for (int k = j; k <= 3; k++) {
        for (int l = k; l <= 3; l++) {
          v.push_back(1ll * i * 10000 + j * 1000 + k * 100 + l * 10 + 3);
        }
      }
    }
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = i; j <= 3; j++) {
      for (int k = j; k <= 3; k++) {
        for (int l = k; l <= 3; l++) {
          for (int m = l; m <= 3; m++) {
            v.push_back(1ll * i * 100000 + j * 10000 + k * 1000 + l * 100 + m * 10 + 3);
          }
        }
      }
    }
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = i; j <= 3; j++) {
      for (int k = j; k <= 3; k++) {
        for (int l = k; l <= 3; l++) {
          for (int m = l; m <= 3; m++) {
            for (int n = m; n <= 3; n++) {
              v.push_back(1ll * i * 1000000 + j * 100000 + k * 10000 + l * 1000 + m * 100 + n * 10 + 3);
            }
          }
        }
      }
    }
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = i; j <= 3; j++) {
      for (int k = j; k <= 3; k++) {
        for (int l = k; l <= 3; l++) {
          for (int m = l; m <= 3; m++) {
            for (int n = m; n <= 3; n++) {
              for (int o = n; o <= 3; o++) {
                v.push_back(1ll * i * 10000000 + j * 1000000 + k * 100000 + l * 10000 + m * 1000 + n * 100 + o * 10 + 3);
              }
            }
          }
        }
      }
    }
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = i; j <= 3; j++) {
      for (int k = j; k <= 3; k++) {
        for (int l = k; l <= 3; l++) {
          for (int m = l; m <= 3; m++) {
            for (int n = m; n <= 3; n++) {
              for (int o = n; o <= 3; o++) {
                for (int p = o; p <= 3; p++) {
                  v.push_back(1ll * i * 100000000 + j * 10000000 + k * 1000000 + l * 100000 + m * 10000 + n * 1000 + o * 100 + p * 10 + 3);
                }
              }
            }
          }
        }
      }
    }
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = i; j <= 3; j++) {
      for (int k = j; k <= 3; k++) {
        for (int l = k; l <= 3; l++) {
          for (int m = l; m <= 3; m++) {
            for (int n = m; n <= 3; n++) {
              for (int o = n; o <= 3; o++) {
                for (int p = o; p <= 3; p++) {
                  for (int q = p; q <= 3; q++) {
                    v.push_back(1ll * i * 1000000000 + j * 100000000 + k * 10000000 + l * 1000000 + m * 100000 + n * 10000 + o * 1000 + p * 100 + q * 10 + 3);
                  }
                }
              }
            }
          }
        }
      }
    }
  }


  for (int i = 1; i <= 3; i++) {
    for (int j = i; j <= 3; j++) {
      for (int k = j; k <= 3; k++) {
        for (int l = k; l <= 3; l++) {
          for (int m = l; m <= 3; m++) {
            for (int n = m; n <= 3; n++) {
              for (int o = n; o <= 3; o++) {
                for (int p = o; p <= 3; p++) {
                  for (int q = p; q <= 3; q++) {
                    for (int r = q; r <= 3; r++) {
                      v.push_back(1ll * i * 10000000000ll + j * 1000000000ll + k * 100000000 + l * 10000000 + m * 1000000 + n * 100000 + o * 10000 + p * 1000 + q * 100 + r * 10 + 3);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  for (int i = 1; i <= 3; i++) {
    for (int j = i; j <= 3; j++) {
      for (int k = j; k <= 3; k++) {
        for (int l = k; l <= 3; l++) {
          for (int m = l; m <= 3; m++) {
            for (int n = m; n <= 3; n++) {
              for (int o = n; o <= 3; o++) {
                for (int p = o; p <= 3; p++) {
                  for (int q = p; q <= 3; q++) {
                    for (int r = q; r <= 3; r++) {
                      for (int s = r; s <= 3; s++) {
                        v.push_back(1ll * i * 100000000000ll + j * 10000000000ll + k * 1000000000ll + l * 100000000 + m * 10000000 + n * 1000000 + o * 100000 + p * 10000 + q * 1000 + r * 100 + s * 10 + 3);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  // for (auto x : v) {
  //   cout << x << '\n';
  // }

  cout << v[n] << '\n';

  return 0;
}