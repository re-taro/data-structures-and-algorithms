#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename T>
T gcd(T a, T b) {
  if (b == 0) {
    return a;
  }
  return gcd<T>(b, a%b);
}

int main() {
  int a = 0;
  int b = 0;
  cin >> a >> b;
  cout << gcd<int>(a, b) << endl;
  return 0;
}
