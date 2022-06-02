#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct ListNode {
  struct ListNode *next = nullptr;
  string data;
} typedef ListNode;

template<typename T>
class Stack {
private:
  ListNode *top = nullptr;
public:
  [[maybe_unused]] explicit Stack(T data) {
    top = new ListNode;
    top->data = std::move(data);
    top->next = nullptr;
  };
  ListNode *push(T data) {
    auto new_node = new ListNode;
    new_node->data = std::move(data);
    new_node->next = top;
    top = new_node;
    return top;
  };
  void printNodes() {
    auto count = 0;
    auto tmp = top;
    while (tmp){
      cout << tmp->data << endl;
      tmp = tmp->next;
      count++;
    }
  };
};


int main() {
  vector<string> data_set = { "Precise", "Quantal", "Saucy",  "Raring"};
  Stack<string> s("Xenial");
  for (const auto &item : data_set) {
    s.push(item);
  }
  s.printNodes();
  return 0;
}
