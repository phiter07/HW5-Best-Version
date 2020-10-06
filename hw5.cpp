/***
* PSUEDOCODE
  BubbleSort (vector string &vec)
    for i less than vec.size
      display vec[i]
    for i < than vec.size
    for j < than vec.size
      if vec[i].compare(vec[i+1])
        if vec[i] is  > than vec[j]
          swap vec[i],vec[j]
        else if vec[i] is < than vec[j]
          swap vec[i], vec[j]
-----------------------------------------------
  void InsertionSortHelper (vector<int>&v, in n)
    initialize temp to v[n-1]
    initialize index to n - 2

    if n is > than 0
      call InsertionSortHelper 
    while index >= 0 && temp < v[index]
      v[index +1] is = to v[index]
      decrement index by 1
    initialize temp to temp
  
  void InsertionSort(vector<int>&v)
    call InsertionSortHelper
-----------------------------------------------
  void Merge (vector<string> &vec, int low, int high)
    initialize mid to (low + high) divided by 2
    initialize i to low
    initialize j to mid + 1 
    initialize k to low
  while i is <= mid and j is <= high
    if vec[i] is less than vec[j]
      assign temporay[k++] to vec[in++]
    else
      assign temporary[k++] to vec[j++]
  while i is <= mid
    assign temporary[k++] to vec[i++]
  while j is <= high
    assign temporary[k++] to vec[j++]
  for i is = to low and i is <= high
    temporary assign vec[i] to temp[i]


  void MergeSortHelper(vector<string> &vec,int low, int high)
    set middle as an int
      if low is >= to high
        return
    set middle = to the sum of low and high divided by 2
    Call the function MergeSortHelper(vec, low, middle)
    Call the function MergeSortHelper(vec, middle + 1, high)
    Call the function Merge(vec, low, high)
  

  void MergeSort(vector<string>, &vec)
    initialize n to vec.size
    Call the function MergeSortHelper(vec,0,n-1)
***/

#include <iostream>
#include <vector>
#include "hw5.h"

void BubbleSort(std::vector<std::string> &vec) {
  for (int i = 0; i < vec.size(); i++)
  std::cout << vec[i] << ' ';

  for (int i = 0; i < vec.size(); i++) {
    for (int j = i + 1; j < vec.size(); j++) 
    {
      if (vec[i].compare(vec[i+1])) {
        if (vec[i] > vec[j])
          swap(vec[i],vec[j]);
      }
        else if (vec[i] < vec[j])
          swap(vec[i],vec[j]);
    }
  }
}

void InsertionSortHelper(std::vector<int>&v, int n) {
  int temp = v[n-1];
  int index = n - 2;

  if(n > 0) 
    InsertionSortHelper(v, n - 1);
  
  while(index >= 0 && temp < v[index]) {
    v[index + 1] = v[index];
    index--;
  }
  v[index + 1] = temp;
}

void InsertionSort(std::vector<int>&v) {
  InsertionSortHelper(v, v.size());
}

void Merge(std::vector<std::string> &vec, int low, int high) {
  int mid = (low + high)/2;
  int i = low;
  int j = mid + 1;
  int k = low;

  std::vector<std::string> temp(vec.size());

  while(i <= mid && j <= high) {
    if(vec[i] < vec[j])
      temp[k++] = vec[i++];
    else 
      temp[k++] = vec[j++];
  }
  
  while(i <= mid) 
    temp[k++] = vec[i++];
  while(j <= high) 
    temp[k++] = vec[j++];
  for(int i = low; i <= high; i++) 
    vec[i]= temp[i];
}

void MergeSortHelper(std::vector<std::string> &vec,int low, int high) {
  int middle;
    if (low >= high)
      return;

  middle = (low + high) / 2;
  MergeSortHelper(vec, low, middle);
  MergeSortHelper(vec, middle + 1, high);
  Merge(vec, low, high); 
}

void MergeSort(std::vector<std::string> &vec) {
  int n = vec.size();
  MergeSortHelper(vec, 0 , n-1);
}