#include <bits/stdc++.h>

#ifndef cpheader
#define F0R(i,a,b) for (int i = a; i < b; ++i)
#define f0r(i,b) F0R(i,0,b)
#define F0Rd(i,a,b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef std::vector<int> vi;
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}
#define cpheader
#endif


using namespace std;

int z[2][500][500];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m, b, mod;
  cin >> n >> m >> b >> mod;
  vi a(n, 0);

  f0r(i, n) { cin >> a[i]; }

  f0r(i, 3) {
    f0r(j, m) {
      
    }
  }

  

  return 0;
}
