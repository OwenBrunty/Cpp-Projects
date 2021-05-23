/*
Owen Brunty
Binary Search Tree
 */
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;



typedef struct nodestruct {
  int data;
  struct nodestruct* rightchild;
  struct nodestruct* leftchild;
}node;

node *root = NULL;

//add function
void addnoderecurs(node** pointer, int x) {
  if (*pointer == NULL) {
    node* newnode = new node;
    newnode -> data = x;
    newnode -> rightchild = NULL;
    newnode -> leftchild = NULL;
    *pointer = newnode;
    return;
  }
  if ((*pointer)->data > x) {
    addnoderecurs(&((*pointer)-> leftchild), x);
  }
  else {
    addnoderecurs(&((*pointer)-> rightchild), x);
  }
}

//function to make inputting what to add cleaner
void addnode(int x) {
  addnoderecurs(&root, x);
}

//function that searchest for the right most child, which is the largest number
int rightmostchild(node* np) {
  if (np -> rightchild != NULL) {
    return rightmostchild(np-> rightchild);
  }
  else {
    return np->data;
  }
}

//delete function 
void deletenoderecurs(node** npp, int x) {
  if (*npp == NULL) {
    return;
  }
  if ((*npp) -> data == x) {
    if ((*npp) -> rightchild == NULL && ((*npp)-> leftchild == NULL)) {
      *npp = NULL;
      return;
    }
    else if ((*npp) -> rightchild == NULL) {
      (*npp) = (*npp)->leftchild;
    }
    else if ((*npp)-> leftchild == NULL) {
      *npp = (*npp)-> rightchild;
    }
    else {
      int temp = rightmostchild((*npp)->leftchild);
      (*npp)->data = temp;
      deletenoderecurs(&((*npp) -> leftchild), temp);
    }
  }
  else {
    if (x < (*npp)->data) {
      deletenoderecurs(&((*npp) -> leftchild), x);
    }
    else {
      deletenoderecurs(&((*npp)-> rightchild), x);
    }
  }
}

//function to make inputting what to delete cleaner
void deletenode(int x) {
  deletenoderecurs(&root, x);
}

//search function
bool searchhelper(node* np, int x) {
  if (np == NULL) {
    return false;
  }
  if (np-> data == x) {
    return true;
  }
  else if (np -> data > x) {
    return searchhelper(np-> leftchild, x);
  }
  else {
    return searchhelper(np-> rightchild, x);
  }
}

//function to make inputting what to search cleaner
bool search(int x) {
  return searchhelper(root, x);
}

//function that prints if the node was found or not
void checkfor(int x) {
  cout << "Checking for: " << x << "    ";
  if (search(x)) {
    cout << "Found in tree" << endl;
  }
  else {
    cout << "Could not find in tree" << endl;
  }
}




//get the numbers for the tree
void input() {
  cout << "Enter name of file containing numbers or type 'manual' to manually enter numbers." << endl;
  char file[20];
  cin >> file;
  //get the file by name
  ifstream numberfile;
  numberfile.open(file);
  //if file not found
  if (!numberfile) {
    if (strcmp(file, "manual") != 0) {
      cout << "File not found: " << file << "          Switching to manual input" << endl;
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
        addnode(input);
      }
    }
  }
  else {
    //if file is found
    int temp;
    while (numberfile >> temp) {
      addnode(temp);
    }
  }
}



//print function
void printtreehelper(node* np, string prefix){
  if (np == NULL) {
    return;
  }
  printtreehelper(np-> rightchild, prefix + "   ");
  cout << prefix << np->data << endl;
  printtreehelper(np-> leftchild, prefix + "   ");
}

//function to make print function in main cleaner
void printtree() {
  printtreehelper(root, "");
}

int main(){
  bool playing = true;
  cout << "To use the binary search tree, type add to add a number, del to delete a number, search to search for a number, print to print the tree, or quit to stop the program." << endl;
  cout << endl;
  input();
  printtree();
  char input[20];
  while (playing) {
    //read in an input and call a function accordingly
    cin >> input;
    //add a number
    if (strcmp(input, "add") == 0) {
      cout << "Enter the number you want to add to the tree." << endl;
      int x;
      cin >> x;
      addnode(x);
      cout << "Added " << x << " to the tree." << endl;
    }
    //delete a number
    else if (strcmp(input, "del") == 0) {
      cout << "Enter the number you want to delete from the tree." << endl;
      int x;
      cin >> x;
      deletenode(x);
      cout << "Deleted " << x << " from the tree." << endl;
    }
    //search for a number
    else if (strcmp(input, "search") == 0) {
      cout << "Enter the number you want to search for." << endl;
      int x;						    				    
      cin >> x;
      checkfor(x);
    }
    //print tree
    else if (strcmp(input, "print") == 0) {
      cout << "Printing the tree." << endl;
      printtree();
    }
    //quit program
    else if (strcmp(input, "quit") == 0) {
      cout<< "Do you want to quit the program? If so enter 'yes'." << endl;
      char quit[5];
      cin >> quit;
      if (strcmp(quit, "yes") == 0) {
	playing = false;	
      }
      else {
	cout << "The program will continue." << endl;
      }
    }
    //unrecognized input
    else {
      cout << "Command not recognized." << endl;
    }
  }
}
