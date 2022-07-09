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
T partitionVec(vector<T> &vec, size_t start, size_t end) {
  T pivot = vec.at(start);
  auto lh = start + 1;
  auto rh = end;
  while (true) {
    while (lh < rh && vec.at(rh) >= pivot) {
      rh--;
    }
    while (lh < rh && vec.at(lh) < pivot) {
      lh++;
    }
    if (lh == rh) {
      break;
    }
    T tmp = vec.at(lh);
    vec.at(lh) = vec.at(rh);
    vec.at(rh) = tmp;
  }
  if (vec.at(lh) >= pivot) {
    return start;
  }
  vec.at(start) = vec.at(lh);
  vec.at(lh) = pivot;
  return lh;
}

template<typename T>
void sort(vector<T> &vec, size_t start, size_t end) {
  if (start >= end) {
    return;
  }
  auto boundary = partitionVec(vec, start, end);
  sort(vec, start, boundary);
  sort(vec, boundary + 1, end);
}

template<typename T>
void quickSort(vector<T> &vec) {
  sort(vec, 0, vec.size() - 1);
}

template<typename T>
int binarySearch(vector<T> &vec, T &item, int s1, int s2) {
  if (s1 > s2) {
    return 0;
  }
  auto middle = (s1 + s2) / 2;
  if (item == vec.at(middle)) {
    return middle;
  }
  if (item > vec.at(middle)) {
    return binarySearch(vec, item, middle + 1, s2);
  } else {
    return binarySearch(vec, item, s1, middle - 1);
  }
}

template<typename T>
int search(vector<T> &vec, T &item) {
  quickSort(vec);
  return binarySearch(vec, item, 0, vec.size() - 1);
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
