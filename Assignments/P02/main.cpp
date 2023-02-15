/*********************************************************************
 *
 *  Author:           Delton Hughes
 *  Email:            dlhughes0129@my.msutexas.edu
 *  Label:            P02
 *  Title:            Vector Class- Operator Overloading 
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *    This program is creating an entire class called Vectors using
 *   a linked list. Said class Vector will have several methods to create
 *   a list and manipulate this list at your own whim. From pushing a
 *   integer to the front of the list or to the back, or sorting
 *   a dynamically made array into ascending order.
 *   At the end of the program it will print the result to the outfile.
 *   (UPDATE) WE created several overloaded operators to allow for 
 *   convenience for the user. 
 * 
 *  Usage:
 *       -Allows the user to dynamicall create a linked list or a Vector
 *       -Also allows for user to +,-,*, print to outfile using fout <<, 
 *         print to console using cout <<, use [] to insert an integer, 
 *         and lastly check if 2 vectors are equivalent using ==. 
 *
 *  Files:
 *       main.cpp      :driver program
 *       output.txt    :txt file printint program output
 **********************************************************************/
#include <fstream>
#include <iostream>
#include <string>

#define INF 1000000000 // infinity

using namespace std;

// Node for our linked list
struct Node {
  int data;

  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

class MyVector {
private:
  Node *head;                    // creating first node
  Node *tail;                    // creating last node 
  int size;                      // creating size instance
  static ofstream fout;
  string fileName;
  bool sorted;

    /**
   * Public : void _inorderPush(int x) 
   *
   * Description:
   *  Takes the given list and organized the integers
   *  into increasing order(smallest to largest). 
   * Params:
   *      - int x
   *
   * Returns:
   *      - void
   */
  void _inorderPush(int x) {
    Node *tempPtr = new Node(x); // allocate new node
    Node *prev = head;           // get previous and next pointers
    Node *curr = head;

    while (curr->data > x) {     // loop to find proper location
      prev = curr;
      curr = curr->next;
    }

    tempPtr->next = prev->next;  // add new node in its proper position
    prev->next = tempPtr;

    size++;                      // add to size :)
  }

public:
  int listLength;
  /**
   * Public : MYVector
   *
   * Description:
   *     Uses init to intiliaze the properties of 
   *        MyVector.
   * Params:
   *      -None
   *
   * Returns:
   *      - Nothing
   */
  MyVector() { init(); }

  /**
   * Public : MyVector(int A[], int aSize)
   *
   * Description:
   *   Takes in an array and the size or amount also increments size
   *   creates two nodes traverse and temp is dynamically created. 
   * Params:
   *      - an integer array
   *      - an integer amount
   *
   * Returns:
   *      - nothing
   */
  MyVector(int A[], int aSize) {
    init();

    for (int i = 0; i < aSize; i++) {
      pushRear(A[i]);
    }
  }

  /**
   * Public : MyVector(string FileName)
   *
   * Description:
   *   Passes in an input filename opens it and
   *   reads in the integers in the file.
   * Params:
   *      - string FileName
   
   *
   * Returns:
   *      - nothing
   */
  MyVector(string FileName) {
    init();

    ifstream fin;
    int x = 0;

    fin.open(FileName);
    while (!fin.eof()) {
      fin >> x;
      pushRear(x);
    }
  }

 /**
   * Public : MyVector(const MyVector &other)
   *
   * Description:
   *  Passes vector V1 by reference in goes through the list
   *  and gets the data that was in said list. Copy Constructors weird cousin.
   * Params:
   *      - Vector &V1
   *
   * Returns:
   *      nothing
   */
  MyVector(const MyVector &other) {
    init();

    Node *temp = other.head;

    while (temp) {
      pushRear(temp->data);
      temp = temp->next;
    }
  }
  /**
   * Public :void init()
   *
   * Description:
   *    Initiliazes default values for a vector.     
   * 
   * 
   * Params:
   *      -None
   *
   * Returns:
   *      - Nothing
   */
  void init() {
    head = tail = NULL;
    fileName = "";
    size = 0;
    sorted = 0;
  }

   /**
   * Public : void inorderPush(int x) 
   *
   * Description:
   *  Takes the given list and organized the integers
   *  into increasing order(smallest to largest). 
   * Params:
   *      - int x
   *
   * Returns:
   *      - void
   */
  void inorderPush(int x) {
    if (!sorted) {
      sortList();
    }

    if (!head) {
      pushFront(x);    // call push front for empty list (or pushRear would work)
    } else if (x < head->data) {
      pushFront(x);    // call push front if x is less than head
    } else if (x > tail->data) {
      pushRear(x);     // call push rear if x > tail
    } else {
      _inorderPush(x); // call private version of push in order
    }
  }

  /**
   * @brief Sort the current values in the linked list.
   *
   * @returns None
   */
  void sortList() {
    Node *newFront = head;
    while (newFront->next) {
      Node *smallest = newFront;
      Node *current = newFront;
      int minimum = INF;
      while (current) {
        if (current->data < minimum) {
          smallest = current;
          minimum = current->data;
        }
        current = current->next;
      }
      smallest->data = newFront->data;
      newFront->data = minimum;
      newFront = newFront->next;
    }
    sorted = true;
  }

   /**
   * Public : void pushFront(int x)
   *
   * Description:
   *   Pushes the value in the parameter to the front
   *   of the list. 
   * Params:
   *      - int x

   *
   * Returns:
   *      - void
   */
  void pushFront(int x) {
    Node *tempPtr = new Node(x);
                             // empty list make head and tail
                            // point to new value
    if (!head) {
      head = tail = tempPtr;                    
    } else {                 // otherwise adjust head pointer
      tempPtr->next = head;
      head = tempPtr;
    }
    size++;
  }

    /**
   * Public:void pushFront(const MyVector &other) 
   *
   * Description:
   *   Is suppose to push an entire list into the front 
   *   of another list. 
   * Params:
   *      - const MyVector &other
   *
   * Returns:
   *      - void
   */
  void pushFront(const MyVector &other) {
    Node *otherPtr = other.head;         // get copy of other lists head
    int *tempData = new int[other.size]; // allocate memory to hold values

                                         // load other list into array
    int i = 0;
    while (otherPtr) {
      tempData[i] = otherPtr->data;
      otherPtr = otherPtr->next;
      ++i;
    }

                                         // process list in reverse in order to keep them
                                         // in their original order.
    for (int i = other.size - 1; i >= 0; i--) {
      pushFront(tempData[i]);
    }
  }

  /**
   * Public :void pushRear(const MyVector& other)
   *
   * Description:
   *  Takes the given list and organized the integers
   *  into increasing order(smallest to largest).
   * Params:
   *      - const MyVector& other
   *
   * Returns:
   *      - void
   */
  void pushRear(const MyVector &other) {
    Node *otherPtr = other.head;     // get copy of other lists head

    while (otherPtr) {               // traverse and add
      pushRear(otherPtr->data);
      otherPtr = otherPtr->next;
    }
  }

    /**
   * Public : bool pushAt(int i, int x)
   *
   * Description:
   *   Takes what is in the location of the indeces
   *   and pushes it to desired location. 
   * Params:
   *      - int i
   *      -  int x

   *
   * Returns:
   *      - bool
   */
  bool pushAt(int i, int x) {
    if (i >= size) {
      return false;
    }

    Node *tempPtr = new Node(x); // allocate new node
    Node *prev = head;           // get previous and next pointers
    Node *curr = head;

    while (i > 0) {              // loop to find proper location
      prev = curr;
      curr = curr->next;
      i--;
    }

    tempPtr->next = prev->next;  // add new node in its proper position
    prev->next = tempPtr;

    size++;                      // add to size :)
    return true;
  }

   /**
   * Public:  void pushRear(int x)
   *
   * Description:
   *  Does exactly what pushFront does but pushes the int value
   *  to the back of the list.
   * Params:
   *      - int x

   *
   * Returns:
   *      - void
   */
  void pushRear(int x) {
    Node *tempPtr = new Node(x);

    if (!head) {
      head = tail = tempPtr;

    } else {
      tail->next = tempPtr;
      tail = tempPtr;
    }
    size++;                 // add to size of list
  }
  /**
   * Public : int find(int val)
   *
   * Description:
   *  Put in a integer value and find that value in a given list
   *  and find it.
   * Params:
   *      -int val
   *
   * Returns:
   *      -integer
   */
  Node *find(int index) {
    int i = 0;
    Node *trav = head;

    while (trav && index != i) {
      trav = trav->next;
      i++;
    }

    return trav;
  }
  /**
   * Public : void deleteV()
   *
   * Description:
   *  Essentially deletes a given list so we can use
   *  the assignment operator properly. 
   * Params:
   *      -none
   *
   * Returns:
   *      -void
   */
  void deleteV() {
    Node *trav = head;
    Node *trail = head;
    while (trav) {
      trail = trav;
      trav = trav->next;
      delete trail;
    }
    head = tail = nullptr;
  }

  /*
   * Public :friend ostream& operator<<(ostream& os, const MyVector& rhs)
   *
   * Description: 
   *  Overloads the << operator to print out to console. 
   *  
   *  
   *
   * Params:
   *      - ostream& os
   *      - const MyVector&rhs
   *
   * Returns:
   *      -os ---> returns to console
   */
  friend ostream &operator<<(ostream &os, const MyVector &rhs) {
    Node *temp = rhs.head; // temp pointer copies head
    os << "[";
    while (temp) {         // this loops until temp is NULL
                           // same as `while(temp != NULL)`

      os << temp->data;    // print data from Node
      if (temp->next) {
        os << ",";
      }
      temp = temp->next;   // move to next Node
    }
    os << "]" << endl;

    return os;
  }
  /*
   * Public :friend ofstream& operator<<(ofstream& os, const MyVector&rhs)
   *
   * Description:
   *  Overloads the << operator to print out to outfile. 
   *  Example Output: [1,2,3,4]
   *
   * Params:
   *      - ofstream& os
   *      - const MyVector&rhs
   *
   * Returns:
   *      -os ---> returns to output.txt
   */
  friend ofstream &operator<<(ofstream &os, const MyVector &rhs) {
    Node *temp = rhs.head;// temp pointer copies head
    os << "[";
    while (temp) {        // this loops until temp is NULL
                          // same as `while(temp != NULL)`
      os << temp->data;   // print data from Node
      if (temp->next) {
        os << ",";
      }
      temp = temp->next;  // move to next Node
    }
    os << "]" << endl;
    return os;
  }
  /*
   * Public : bool operator==(const MyVector &rhs)
   *
   * Description:
   *      Checks to see if two different vectors
   *      are equivalent. 
   * 
   * Params:
   *      - const MyVector &rhs
   *
   * Returns:
   *      -bool- True(1) or Fales(0)
   */
  bool operator==(const MyVector &rhs) {
    if (&rhs == this) {                //if both are equal then true 
      return true;
    }

    Node *trav = this->head;           // left hand side reading
    Node *trav1 = rhs.head;            // right hand side reading
     
    while (trav && trav1) {            //break case
      if (trav->data != trav1->data) { //checks if data is equivalent
        return false;                  //if not false
      }
      trav = trav->next;               //traverse trav
      trav1 = trav1->next;             //traverse trav
    }
    return true;
  }

  /*
   * Public :void operator=(const MyVector &rhs)
   *
   * Description:
   *     Uses the assignment operator '=' to assign 
   *     a vector. 
   * Params:
   *      - const MyVector&rhs
   *
   * Returns:
   *      -nothing
   */
  void operator=(const MyVector &rhs) {
    if (&rhs == this)
      return;

    if (head) {
      this->deleteV();
    }
    Node *travel = rhs.head;
    while (travel) {
      this->pushRear(travel->data);
      travel = travel->next;
    }
  }

  /*
   * Public :int &operator[](int index)
   *
   * Description:
   *       Use the '[]' operator to insert a integer into
   *        a already created list. 
   *
   * Params:
   *      - int index
   *
   * Returns:
   *      -int
   */
  int &operator[](int index) {
    Node *temp = find(index);
    return temp->data;
  }
  /*
   * Public :MyVector operator+(const MyVector &rhs)
   *
   * Description:
   *    Uses the '+' operator to add Vectors. 
   *
   * Params:
   *      - const MyVector&rhs
   *
   * Returns:
   *      -MyVector
   */
  MyVector operator+(const MyVector &rhs) {
    MyVector V;
                      // check to see which vector is the shortest
    Node *shortest;
    Node *longest;
                      // loop over shortest vector
    if (rhs.size < this->size) {
      shortest = rhs.head;
      longest = this->head;
    } else {
      shortest = this->head;
      longest = rhs.head;
    }

    while (shortest) { // push added values onto V
      V.pushRear(shortest->data + longest->data);

      longest = longest->next;
      shortest = shortest->next;
    }

    while (longest) { // push added values onto V
      V.pushRear(longest->data);
      longest = longest->next;
    }
    return V;
  }
  /*
   * Public :MyVector operator*(const MyVector &rhs)
   *
   * Description:
   *        Uses '*' operator to multiply Vectors. 
   *
   * Params:
   *      - const MyVector&rhs
   *
   * Returns:
   *      -MyVector
   */
  MyVector operator*(const MyVector &rhs) {
    MyVector V;
                        // check to see which vector is the shortest
    Node *shortest;
    Node *longest;
                        // loop over shortest vector
    if (rhs.size < this->size) {
      shortest = rhs.head;
      longest = this->head;
    } else {
      shortest = this->head;
      longest = rhs.head;
    }

    while (shortest) {  // push added values onto V
      V.pushRear(shortest->data * longest->data);

      longest = longest->next;
      shortest = shortest->next;
    }

    while (longest) {  // push added values onto V
      V.pushRear(longest->data);
      longest = longest->next;
    }
    return V;
  }
  /*
   * Public :MyVector operator-(const MyVector &rhs)
   *
   * Description:
   *       Uses the '-' operator to subtract vectors. 
   *
   * Params:
   *      - const MyVector&rhs
   *
   * Returns:
   *      -MyVector
   */
  MyVector operator-(const MyVector &rhs) {
    MyVector V;
    Node *rHS;             //Node trav right hand side
    Node *lHS;             //Node trav left hand side

    lHS = this->head;      //assign left to equal left list
    rHS = rhs.head;        //assign right to equal right list
                        
      while (rHS && lHS) { // loop over 
        V.pushRear(lHS->data - rHS->data);
                           //subtract and traverse
        lHS = lHS->next;
        rHS = rHS->next;
      }
      while (lHS) {        // push subtract values onto V
        V.pushRear(lHS->data);
        lHS = lHS->next;
      }
      while(rHS) {         // push subtract values onto V
        V.pushRear(rHS->data);
        rHS = rHS->next;
      }
    
    return V;
  }

    /*
   * Public :~MyVector()
   *
   * Description:
   *    Deletes values in list to free up memory. 
   *
   * Params:
   *      - none
   *
   * Returns:
   *      -none
   */
  ~MyVector() {
    Node *curr = head;
    Node *prev = head;

    while (curr) {
      prev = curr;
      curr = curr->next;
      delete prev;
    }
  }
};

int main() {

  int a1[] = {1, 2, 3, 4, 5};
  int a2[] = {10, 20, 30};

  MyVector v1(a1, 5);
  MyVector v2(a2, 3);

  ofstream fout;
  fout.open("output.txt");

  cout << v1[2] << endl;
  fout << v1[2] << endl;
  // writes out 3

  v1[4] = 9;
  // v1 now = [1,2,3,4,9]

  cout << v1 << endl;
  // writes out [1,2,3,4,9] to console.

  fout << v1 << endl;
  // writes out [1,2,3,4,9] to your output file.

  MyVector v3 = v1 + v2;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [11,22,33,4,9] to console.

  cout << "========" << endl;
  cout << v1 << endl;
  cout << v2 << endl;

  v3 = v1 - v2;

  
  cout << v3 << endl;
  fout << v3 << endl;
  cout << "========" << endl;
  // writes out [-9,-18,-27,4,9] to console.

  v3 = v2 - v1;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [9,18,27,4,9] to console.

  v3 = v2 * v1;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [10,40,90,4,9] to console.

  v3 = v1 * v2;
  cout << v3 << endl;
  fout << v3 << endl;
  // writes out [10,40,90,4,9] to console.

  // v3 = v1 / v2;
  // cout << v3 << endl;
  // writes out [0,0,0,4,9] to console.

  // v3 = v2 / v1;
  // cout << v3 << endl;
  // writes out [10,10,10,4,9] to console.

  cout << (v2 == v1) << endl;
  fout << (v2 == v1) << endl;
  //  writes 0 to console (false) .

  MyVector v4 = v1;
  cout << (v4 == v1) << endl;
  fout << (v4 == v1) << endl;
  // writes 1 to console (true) .
}