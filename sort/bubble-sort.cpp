#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

template<typename T>
void printVector(const vector<T> &vec) {
  for ([[maybe_unused]] auto &i : vec) {
    cout << i << "; ";
  }
  cout << endl;
}

template<typename T>
void bubbleSort(vector<T> &vec) {
  for (size_t i = 0; i < vec.size() - 1; ++i) {
    for (size_t j = 0; j < vec.size() - i - 1; ++j) {
      if (vec.at(j) > vec.at(j + 1)) {
        std::swap(vec.at(j), vec.at(j + 1));
      }
    }
  }
}

int main(int argc, char* argv[]) {
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
    bubbleSort(vec);
    printVector(vec);
    return 0;
  }
  catch (std::exception& e) {
    cout << e.what() <<endl;
    return -1;
  }
}
