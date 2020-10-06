#include <iostream>
#include <vector>
#include "hw5.h"

void print(std::vector<std::string> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

void print2(std::vector<int> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> v;
  std::vector<std::string> k;


  v = {"emma", "dora", "ruth", "ziegellaub", "eichler"};
  std::cout << "Case 1: Bubble Sort" << std::endl;
  BubbleSort(v);
  std::cout << std::endl;
  print(v);
  std::cout << std::endl << std::endl;

  std::vector<int> vec;
  MergeSort(v);
  std::cout << "Case 2: Insertion Sort " << std::endl;
  //vec = {11, 20, 24, 8, 10, 1, 3, 4, 34, 14};
  vec = {-1, 0,34, 65, 79, 56, 65, 9, 2, 5, 1000, 101};
  InsertionSort(vec);
  print2(vec);
  std::cout << std::endl;
  

  k = {"Kobe", "Balls", "Jenkins", "Leeroy", "Ligma", "Bryant"};
  MergeSort(k);
  std::cout << "Case 3: MergeSort " << std::endl;
  print(k);
  //std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;

  //blah
}