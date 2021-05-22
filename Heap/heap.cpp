/*
Heap.cpp
Owen Brunty
5/21/21
*/
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int heap[101];
int heapsize = 0;

//returns the left child of node n
int leftchild(int n) {
  return 2*n;
}

//returns the right child of node n
int rightchild(int n) {
  return 2*n + 1;
}

//returns the parent of node n
int parent (int n) {
  return n/2;
}

//print
void printheapfrom(int n, string prefix) {
  //checks for finished sub tree
  if (n > heapsize) {
    return;
  }
  printheapfrom(rightchild(n), prefix+"   ");
  cout << prefix << heap[n] << endl;
  printheapfrom(leftchild(n), prefix+"   ");
}

//print the heap
void printheap() {
  cout << "Heap of size " << heapsize << ":" << endl;
  printheapfrom(1, "");
}

//swaps two nodes in the heap
void swap(int x, int y){
  int temp;
  temp = heap[x];
  heap[x] = heap[y];
  heap[y] = temp;
}

//checks if parent is bigger than node n if not then swap
void checkparent(int n) {
  //checks if its the root
  if (n == 1) {
    return;
  }
  if (heap[parent(n)] > heap[n]) {
    return;
  }
  else {
    swap(n, parent(n));
    checkparent(parent(n));
  }
}

//check if children are smaller than node n if not then swap
void checkchildren(int n) {
  if (leftchild(n) > heapsize) {
    return;
  }
  if (rightchild(n) > heapsize) {
    if (heap[leftchild(n)] < heap[n]) {
      return;
    }
    else {
      swap(n, leftchild(n));
      return;
    }
  }
  if (heap[leftchild(n)] > heap[rightchild(n)]) {
    swap(n, leftchild(n));
    checkchildren(leftchild(n));
  }
  else {
    swap(n, rightchild(n));
    checkchildren(rightchild(n));
  }
}

//remove the head node
int removemax() {
  if (heapsize == 0){
    return -1;
  }
  int rv;
  rv = heap[1];
  heap[1] = heap[heapsize];
  heapsize--;
  checkchildren(1);
  return rv;
}

//add a node to heap
void addtoheap(int x) {
  heapsize++;
  heap[heapsize] = x;
  checkparent(heapsize);
}

//get the numbers for heap
void input() {
  cout << "Enter name of file containing numbers, type 'manual' to manually enter numbers." << endl;
  char file[20];
  cin >> file;
  //get the file by name
  ifstream numberfile;
  numberfile.open(file);
  //if file not found
  if (!numberfile) {
    if (strcmp(file, "manual") != 0) {
      cout << "File not found: " << file << endl;
    }
    //manual number entry
    cout << "Enter a number to add to the heap, enter '-1' nothing when you are finished" << endl;
    bool inputting = true;
    while(inputting) {
      int input;
      cin >> input;
      if (input == -1) {
        cout << "Stopping insertion." << endl;
        inputting = false;
      }
      else {
        addtoheap(input);
      }
    }
  }
  else {
    //if file is found
    int temp;
    while (numberfile >> temp) {
      addtoheap(temp);
    }
  }
}

int main() {
  input();
  printheap();
  while (heapsize > 0) {
    cout << "removed: " << removemax() << endl;
  }
}

