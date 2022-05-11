#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

template<typename T>
void printVector(const vector<T> &vec) {
  for ([[maybe_unused]] auto &i: vec) {
    cout << i << "; ";
  }
  cout << endl;
}

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
    printVector(vec);
    quickSort(vec);
    printVector(vec);
  }
  catch (std::exception &e) {
    cout << e.what() << endl;
    return -1;
  }
}
