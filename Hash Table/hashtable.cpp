/*
Owen Brunty
4/22/21
Hash Table

Used article for refrence: https://www.journaldev.com/35238/hash-table-in-c-plus-plus
*/


#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

//creates a struct that groups all info for a student
struct Student {
  char firstname[20];
  char lastname[20];
  int id;
  float gpa;
};

struct HT_item {
    char* key;
    struct* value;
};

struct HashTable {
    HT_item** items;
    int n;
    int size;
};


//function that hashes students
int hashfunction(int n){
    return Student.id % table -> size;
}


//creaes hash table
HashTable* maketable(int size){
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table -> n =0;
    table -> size = 100;
    table -> items = (HT_item**)calloc(table -> size, HT_item*);

    for(int i = 0; i < table -> size; i++) {
        table -> items[i] = NULL;   
    }
}

//function that will add an entry for a new student
void add(HashTable* table, char* key, struct* value) {
  cout << "\n";
  
  new Student currentStudent();
  cout << "What is the new student's first name?" << endl;
  cin >> currentStudent -> firstname;

  cout << "What is the new student's last name?" << endl;
  cin >> currentStudent -> lastname;
  
  cout << "What is the new student's id?" << endl;
  cin >> currentStudent -> id;
  
  cout << "What is the new student's GPA?" << endl;
  cin >> currentStudent -> gpa;
}

//function that will print all current student's and their information
void print(vector<Student*> studentvector) {
  cout << "\n";
  if (studentvector.empty()) {
    cout << "No students are in the list." << endl;
  }
  for (std::vector<Student*>::iterator it = studentvector.begin(); it != studentvector.end(); it++){
    cout << (*it) -> firstname << " " << (*it) -> lastname << ", " << (*it) -> id << ", " << fixed << setprecision(2) << (*it) -> gpa << endl;
  }
}

//function that will delete a student and their information
void del(vector<Student*> &studentvector) {
  cout << "\n";
  cout << "Enter the id of the student you want to remove from the list." << endl;
  int delid;
  cin >> delid;
  for (std::vector<Student*>::iterator it = studentvector.begin(); it != studentvector.end(); ++it) {
    int x = it - studentvector.begin();
    if (delid == studentvector[x] -> id) {
      delete  studentvector[x];
      studentvector.erase(it);
      cout << "Deleted student wtih id: " << (*it) -> id << endl;
      break;
    }
  }
}

//function that creates a list of randomly generated students
void random() {
    
}



int main() {
  
  bool loop = true;
  char input[10];

  vector<Student*> studentvector;

  //loop that runs until user enters "QUIT"
  while (loop){
    cout << "\n";
    cout << "Enter 'ADD' to add a student, 'DELETE' to delete a student, 'PRINT' to print the list, or 'QUIT' to exit the program." << endl;
    //Depending on user's input it will run the delete, add, or print function
    cin >> input;
    if (strcmp(input, "QUIT") == 0) {
	loop = false;
      }
    else if (strcmp(input, "ADD") == 0) {
      add(studentvector);
	}
    else if (strcmp(input, "PRINT") == 0) {
      print(studentvector);
	}
    else if (strcmp(input, "DELETE") == 0) {
      del(studentvector);
	}
	else if (strcmp(input, "RANDOM") == 0) {
	    random();
	}
    else {
	    cout << "Unrecognized input. Please enter 'ADD', 'PRINT', 'DELETE', or 'QUIT'." << endl;
    }
  }
  return 0;
}
