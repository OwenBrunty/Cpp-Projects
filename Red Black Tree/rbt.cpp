/*
Owen Brunty
Red Black Tree

 */

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

enum colors{red, black};

typedef struct nodestruct {
  int data;
  struct nodestruct* rightchild;
  struct nodestruct* leftchild;
  struct nodestruct* parent;
  enum colors color;
}node;

node *root = NULL;

//add function
node* addnoderecurs(node** pointer, node* parent, int x) {
  if (*pointer == NULL) {
    node* newnode = new node;
    newnode -> data = x;
    newnode -> rightchild = NULL;
    newnode -> leftchild = NULL;
    if (parent == NULL) {
      newnode -> color = black;
    }
    else {
      newnode-> color = red;
    }
    newnode -> parent = parent;
    *pointer = newnode;
    return newnode;
  }
  if ((*pointer)->data > x) {
    return addnoderecurs(&((*pointer)-> leftchild), *pointer, x);
  }
  else {
    return addnoderecurs(&((*pointer)-> rightchild), *pointer, x);
  }
}

node* uncle(node* k){
  if (k == NULL){
    cout << "shouldn't happen 1" << endl;
    return NULL;
  }
  if (k->parent == NULL) {
    cout << "shouldn't happen 2" << endl;
    return NULL;
  }
  node* grand = k->parent->parent;
  if (grand == NULL) {
    cout << "shouldn't happen 3" << endl;
    return NULL;
  }
  if (grand->leftchild == k->parent) {
    return grand->rightchild;
  }
  if(grand->rightchild == k->parent) {
    return grand->leftchild;
  }
  else {
    cout << "Node parent is not grand's child: " << k->data << endl;
    return NULL;
  }
}

void childreplace(node* p, node* from, node* to) {
  if (from->parent == NULL) {
    return;
  }
  if (p->leftchild == from) {
    p->leftchild = to;
  }
  else if (p->rightchild == from) {
    p->rightchild = to;
  }
  else {
    cout << "childreplace from parent doesnt have from as child" << endl;
  }
}

void fixparent(node* g) {
  if (g->rightchild != NULL) {
    g->rightchild->parent = g;
  }
  if (g->leftchild != NULL) {
    g->leftchild->parent = g;
  }
}

void restoretree(node* k) {
  node * p = k-> parent;
  //case 1: case parent is black, nothing violated so nothing to do
  if (p -> color == black) {
    return;
  }
  //case 2: case parent is red
  node* s = uncle(k);
  //case 2a: null or black uncle
  if ((s == NULL) || (s->color == black)) {
    node* g= p-> parent;
    //case 2a -1
    if ((k->data <= p->data) && (p-> data <= g->data)) {
      g->leftchild = p->rightchild;
      g-> rightchild = s;
      node* gp = g->parent;
      fixparent(g);
      g->color = red;
      
      p->rightchild = g;
      p->leftchild = k;
      fixparent(p);
      p-> parent = gp;
      p->color = black;

      if (gp == NULL) {
	root = p;
      }
      else {
	childreplace(gp, g, p);
      }
    }
    //case 2a - 2
    else if ((k->data > p->data) && (p-> data <= g->data)) {
      g->leftchild = NULL;
      g-> rightchild = s;
      node* gp = g->parent;
      fixparent(g);
      g->color = red;

      p->rightchild = NULL;

      k->leftchild = p;
      k->rightchild = g;
      k-> parent = gp;
      k-> color = black;
      fixparent(k);
      if (gp == NULL) {
        root = k;
      }
       else {
        childreplace(gp, g, k);
      }
    }
    //case 2a - 3
    if ((k->data > p->data) && (p-> data > g->data)) {
      g->rightchild = p->leftchild;
      g-> leftchild = s;
      node* gp = g->parent;
      fixparent(g);
      g->color = red;

      p->leftchild = g;
      p->rightchild = k;
      fixparent(p);
      p-> parent = gp;
      p->color = black;

      if (gp == NULL) {
        root = p;
      }
       else {
        childreplace(gp, g, p);
      }
    }

    //case 2a - 4
    else if ((k->data <= p->data) && (p-> data > g->data)) {
      g->rightchild = NULL;
      g-> leftchild = s;
      node* gp = g->parent;
      fixparent(g);
      g->color = red;

      p->leftchild = NULL;

      k->rightchild = p;
      k->leftchild = g;
      k-> parent = gp;
      k-> color = black;
      fixparent(k);
      if (gp == NULL) {
        root = k;
      }
       else {
        childreplace(gp, g, k);
      }
    }
  }
  else {
    //case 2b: k's uncle is red
    node* g= p-> parent;
    p->color = black;
    s->color = black;
    if (g != root) {
      g->color = red;
      if(g->parent->color == red) {
	restoretree(g);
      }
    }
  }
}

//function to make inputting what to add cleaner
void addnode(int x) {
  node* newnode = addnoderecurs(&root, NULL, x);
  if (newnode->parent == NULL) {
    return;
  }
  restoretree(newnode);
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
  string color;
  if (np->color == red) {
    color = "R";
  }
  else {
    color = "B";
    }
  printtreehelper(np-> rightchild, prefix + "   ");
  cout << prefix << color <<" " << np->data << " " << endl;
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
      //deletenode(x);
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
