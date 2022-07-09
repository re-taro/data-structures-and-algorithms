#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

template<typename T>
int search(const vector<T> &arr, T &search_Element) {
  int left;
  int length = arr.size();
  int position;
  int right = length - 1;
  for (left = 0; left <= right;) {
    if (arr[left] == search_Element) {
      position = left;
      return position + 1;
    }
    if (arr[right] == search_Element) {
      position = right;
      return position + 1;
    }
    left++;
    right--;
  }
  return 0;
}

int main(int argc, char *argv[]) {
  try {
    if (argc != 2) {
      throw std::out_of_range("out of range");
    }
    std::ifstream in(argv[1]);
    vector<int> vec;
    string value;
    if (in.fail()) {
      throw std::logic_error("file couldn't open");
    }
    while (!in.eof()) {
      in >> value;
      vec.push_back(std::stoi(value));
    }
    int a = 20293;
    int b = 7789;
    int c = 4021;
    int d = 6586;
    int e = 30000;
    cout << a << ":" << search(vec, a) << endl;
    cout << b << ":" << search(vec, b) << endl;
    cout << c << ":" << search(vec, c) << endl;
    cout << d << ":" << search(vec, d) << endl;
    cout << e << ":" << search(vec, e) << endl;
    return 0;
  }
  catch (std::exception &e) {
    cout << e.what() << endl;
    return -1;
  }
}
