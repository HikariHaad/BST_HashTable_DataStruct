//============================================================================
// Name         : Bst Cpp
// Author       : Haad Mehboob
// Version      : 0
// Date Created : 13-12-2023
// Date Modified: 13-12-2023
//============================================================================

#include "bst.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename T1, typename T2> BST<T1, T2>::BST() { root = nullptr; } // define tree
//=============================================================================
template <typename T1, typename T2> BST<T1, T2>::~BST() {
  DestroyRecursive(root); // helper function to destroy tree recursively
}
//=============================================================================
template <typename T1, typename T2>
void BST<T1, T2>::DestroyRecursive(Node<T1, T2> *ptr) { // recursively deletes the tree nodes
  if (ptr != nullptr) {
    DestroyRecursive(ptr->left);
    DestroyRecursive(ptr->right);
    delete ptr;
  }
}
//=============================================================================
template <typename T1, typename T2> Node<T1, T2> *BST<T1, T2>::getRoot() {
  return root; // simple getter
}
//=============================================================================
template <typename T1, typename T2>
void BST<T1, T2>::insert(Node<T1, T2> *ptr, T1 key, T2 value) { // inserts a new node into the tree
  if (root == nullptr) {
    root = new Node<T1, T2>(key);
    root->value.push_back(value);
    return; // first node insertion
  }
  if (key == ptr->key) {
    for (auto &element : ptr->value) { // when key is already in the tree, find the specific value or hotel in the city
      if (element->getName() == value->getName()) {
        element = value; // renew the hotel details
        cout << "Existing record has been updated." << endl;
        return;
      }
    }
    ptr->value.push_back(value); // add to the vector of values
    return;
  }
  if (key < ptr->key) { // recursive traversal
    if (ptr->left == nullptr) {
      ptr->left = new Node<T1, T2>(key);
      ptr->left->parent = ptr;
      ptr->left->value.push_back(value);
      return;
    }
    insert(ptr->left, key, value);
  } else {
    if (ptr->right == nullptr) {
      ptr->right = new Node<T1, T2>(key);
      ptr->right->parent = ptr;
      ptr->right->value.push_back(value);
      return;
    }
    insert(ptr->right, key, value);
  }
}
//=============================================================================
template <typename T1, typename T2> int BST<T1, T2>::height(Node<T1, T2> *ptr) {
  if (ptr == nullptr)
    return 0;
  return max(height(ptr->left), height(ptr->right)) + 1; // recursively calculates the height of tree
}
//=============================================================================
template <typename T1, typename T2>
Node<T1, T2> *BST<T1, T2>::find(Node<T1, T2> *ptr, T1 key, string stars) {
  if (ptr == nullptr){
    return nullptr;
  }
  if (ptr->key == key) {
    ptr->print(stars); // print the hotel details, the stars input takes care of itself when printing
    return ptr;
  }
  if (key < ptr->key)
    return find(ptr->left, key, stars); // recursive branching
  return find(ptr->right, key, stars);
}
//=============================================================================

template <typename T1, typename T2>
Node<T1, T2> *BST<T1, T2>::findMin(Node<T1, T2> *ptr) {
  if (ptr == nullptr)
    return nullptr;
  while (ptr->left != nullptr)
    ptr = ptr->left;
  return ptr;
}

//=============================================================================
template <typename T1, typename T2>
Node<T1, T2> *BST<T1, T2>::remove(Node<T1, T2> *ptr, T1 key, T2 value) {
  if (ptr == nullptr)
    return ptr; // return when null

  if (key < ptr->key) { // recursive traversal
    ptr->left = remove(ptr->left, key, value);
    return ptr;
  } else if (key > ptr->key) {
    ptr->right = remove(ptr->right, key, value);
    return ptr;
  }

  if (ptr->key == key) { // when found, iterate through the vector at the node to see which element corresponds with the query name, then remove it
    auto it = ptr->value.begin();
    while (it != ptr->value.end()) {
      if ((*it)->getName() == value->getName()) {
        (ptr->value).erase(it);
        return ptr;
      } else {
        ++it;
      }
    }

    if ((ptr->value).empty()) { // whena  node vector gets empty, we reattach it by branching the tree again using tree removal case by case algorithms
      if (ptr->left == nullptr) {
        Node<T1, T2> *temp = ptr->right;
        delete ptr;
        return temp;
      } else if (ptr->right == nullptr) {
        Node<T1, T2> *temp = ptr->left;
        delete ptr;
        return temp;
      } else {
        Node<T1, T2> *succPar = ptr;
        Node<T1, T2> *successor = ptr->right;
        while (successor->left != nullptr) {
          succPar = successor;
          successor = successor->left;
        }
        if (succPar != ptr)
          succPar->left = successor->right;
        else
          succPar->right = successor->right;
        ptr->key = successor->key;
        ptr->value = successor->value;
        delete successor;
        return ptr;
      }
    }
  }
  return ptr;
}
