#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {


  void LinkedList::ReverseIterative() {
    Node* current = front_;
    Node* past = nullptr;
    while (current != nullptr)
    {
      Node* next = current->next;
      current->next = past;
      past = current;
      current = next;
    }
    back_ = front_;
    front_ = past;
  }


  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
    Node* savehead = front_;
    front_ = back_;
    back_ = savehead;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& current, Node* past) {
    if (current != nullptr)
    {
      reverse_recursive_helper(current->next, current);
      current->next = past;
    }
  }

}  // namespace assignment
