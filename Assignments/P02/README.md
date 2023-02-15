## P02-Overloading Operators
### Delton Hughes
### Description:

- This program was to build on top of our previous Vector Class by overloading
operators to help with convenience of use for the user. For example by using 
<<,*,+,-,[] operators we allow the user to do basic math with vectors, print out, 
and to insert a integer to a vector. 



### Files

|   #   | File      | Description                      |
| :---: | --------- | -------------------------------- |
|   1   | main.cpp  | Main driver of my list program . |
|   2   | Banner.cpp| Banner uploaded.                 |                  
|   3   | output.txt| Text File                        |
### Instructions

- Use the commented instructions on how to use method commands.
- Need the #include <fstream> library
- Creates a output.txt
- Layout is like below
```
+--------------+
| [10, 20, 30] |
|  3 //for []  |
|  0 //false   |
|  1 //true    |
|              |
+--------------+
```

### Example Command

*  -  void _inorderPush(int x)       //sets array in order
*  -  MyVector(int A[], int aSize)   //allows us to set an array and its size
*  -  void pushFront(const MyVector &other) //pushes vector to front
*  -  pushRear(const MyVector &other)//pushes vector to rear
*  -  Node *find(int index)          //finds a value
*  -  friend ostream &operator<<(ostream &os, const MyVector &rhs)  //overloads cout
*  -  friend ofstream &operator<<(ofstream &os, const MyVector &rhs)//overloads fout
*  -  bool operator==(const MyVector &rhs)   //sees if vectors are equivalent
*  -  void operator=(const MyVector &rhs)    //assigns a vector
*  -  int &operator[](int index)             //put in indeces and adds the value to vector 
*  -  void operator=(const MyVector &rhs)    //assigns a vector
*  -  MyVector operator+(const MyVector &rhs)//adds vectors
*  -  MyVector operator*(const MyVector &rhs)//multiplies vectors
*  -  MyVector operator-(const MyVector &rhs)//subtracts vectors