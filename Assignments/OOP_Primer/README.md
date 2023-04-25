##A04
-Name: Delton Hughes
-Date: 2/1/2023
-Class: 2143 OOP

##Definitions 

#### Abstraction

> **Definition:** The process of hiding the internal details 
> of an application from the outer world. 
>
>
>  
<img src="https://i.ytimg.com/vi/1eSCCQPBqP0/maxresdefault.jpg" width=250>



#### Attributs/Properties

> **Definition:**
> **Attribute**-particular property of an object, element or file.


> **Properties**-special sort of class member, intermediate in functionality between a field(or data member) and a method.
 
>
><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/98/CPT-OOP-objects_and_classes_-_attmeth.svg/300px-CPT-OOP-objects_and_classes_-_attmeth.svg.png" width=250>



#### Class

> **Definition:** A class is the foundation of OOP, it allows us to 
> create a particular data structure, providing member variables
> and attributs, and implementing member functions or methods. 
> **Coding example:** 
> ```
> class student
> {
>   private:
>     string name;
>     string major;
>     int numClasses; 
>     double GPA;
>   public:
>    //constructor
>    Student(){
>       name = "Nobody";
>       major = "CMPS";
>       numClasses = 0;
>       GPA = 0.0;
>    }
>    //accessor method
>    string getName(){
>        //because this only has access to private
>       return name;
>    }
>    //Mutator function to set the numClasses
>    void setNumClasses(int classes){
>       //Only stores if valid
>       if(classes >=0 && classes <=6)
>           numClasses = classes;
>    }
>    //other member function 
>    bool isHonorRoll(){
>       retunr GPA >= 3.0;
>    }
> };
> ```
> **Picture example:** 
>
><img src="https://www.devopsschool.com/blog/wp-content/uploads/2021/05/Complete-Tutorials-of-PHP-OOP-ClassesObjects-with-Example-code.png" width=250>



#### Class Variable

> **Definition:** A class variable defines a specific attribute or
> property for a class. Like the example below. 
>**Code Example:**
> ```
> class student
> {
>   private:
>     string name;
>     string major;
>     int numClasses; 
>     double GPA;
>   public:
>   etc...
>}
> ```
><img src="https://www.w3resource.com/w3r_images/java-class-image.png" width=250>



#### Composition

> **Definition:** A class that references one or more objects of other classes in instance variables. 
> **Code Example:**
```
#include <iostream>
#include <string>

using namespace std;

class Engine {
public:
    Engine(string model) : m_Model(model) {}
    void start() { cout << "Starting engine " << m_Model << endl; } //<--- here
private:
    string m_Model;
};

class Car {
public:
    Car(string make, string model, Engine engine)
        : m_Make(make), m_Model(model), m_Engine(engine) {}
    void start() { m_Engine.start(); } <--here
private:
    string m_Make;
    string m_Model;
    Engine m_Engine;
};

int main() {
    Engine engine("V6");
    Car car("Toyota", "Camry", engine);
    car.start();
    return 0;
}

``` 
><img src="https://miro.medium.com/v2/resize:fit:828/format:webp/0*J_Dm57bKTppN51oZ.png" width=250>



#### Constructor

> **Definition:** It initializes a newly created object of that type. This could be a copy, default, or even a parameterized constructor. 
> **Code Example:**
```
//Default Constructor 
    Car(){
        make = "Chevorlet";
        model = "Colorado";
        year = "2017";
        price = "$36,000";
    } 
//Copy Constructor
    Car(const Car& other) {
        make = other.make;
        model = other.model;
        year = other.year;
        price = other.price;
    }

//Parameterized Constructor
 Car(string make, string model, int year, float price) {
        this->make = make;
        this->model = model;
        this->year = year;
        this->price = price;
    }
```
><img src="https://static.javatpoint.com/images/core/java-constructor.png" width=250>



#### Encapsulation

> **Definition:** A class that references one or more objects of other classes in instance variables. 

**Code Example:**
```
class Engine {
public:
    void start() { /* implementation */ }
    void stop() { /* implementation */ }
};

class Car {
private:
    Engine engine;
public:
    void start() { engine.start(); }
    void stop() { engine.stop(); }
};

```
>
><img src="https://www.simplilearn.com/ice9/free_resources_article_thumb/Encapsulation_in_Java.png" width=250>



#### Friends

**Definition:** Is put on a function that allows the method to access private and protected data members. 

**Code Example:**
```
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
```


><img src="https://media.geeksforgeeks.org/wp-content/uploads/20220802105339/FriendFunctioninC-660x328.png" width=250>



#### Inheritance

**Definition:** Allows us to derive a class from another class, lets then share a set of methods or attributes. 

**Code Example:**
```
class Shape {
protected:
   
public:

};

class Rectangle : public Shape {
public:
  
};

class Triangle : public Shape {
public:
}
```
><img src="https://media.geeksforgeeks.org/wp-content/uploads/inheritance2.png" width=250>



#### Instance Variable
**Definition:** Has a separate copy or instance in each of the its instances. It is non-static.
```
class Person {
private:
    std::string name;
    int age;
}
```

><img src="https://scaler.com/topics/images/instance-variables-in-memory.webp" width=250>



#### Member Variable
**Definition:** Is a variable assigned to its class which is accessible only to methods within the class and inheritated classes or friended methods.
```
class Person {
private:
    std::string name;
    int age;
}
```

><img src="https://www.w3resource.com/w3r_images/java-class-image.png" width=250>



#### Method
**Definition:** Is a function within a class that manipulates the member variables and/or allows the user to use a the created structure in a variety of ways.
**Code Example:**
```
void pushFront(int val) {
    Node *temp = new Node(val);
    if (head == NULL) {          //when head equals null
      head = temp;
    } else {                     
      temp->next = head;         //The next two lines:
      head->prev = temp;         //These connect the nodes so we 
      head = temp;               //do not lose the data (stitches together)
    }
    size++;                      //increment count
  }      
```
><img src="https://editor.analyticsvidhya.com/uploads/96981images.png" width=250>



#### Multiple Inheritance

**Definition:** Say we have three classes and one is the parent the other is the child and the third is the child of the child. It allows the last child to inherit from the parent of the first child and the original parent. 

**Code Example:**
```
class Shape {
protected:
   
public:

};

class Rectangle : public Shape {
public:
  
};

class Triangle : public Shape {
public:
}
```
><img src="https://media.geeksforgeeks.org/wp-content/uploads/20191222084630/multipleinh.png" width=250>



#### Object
**Defintion:** The things you think about first in designing a program and they are also the units of code that are eventually derived from the process
```
#include <iostream>

class Person {
private:
    std::string name;
    int age;
    
public:
    Person(std::string n, int a) : name(n), age(a) {}
    
    void sayHello() {
        std::cout << "Hello, my name is " << name << " and I am " << age << " years old." << std::endl;
    }
};

int main() {
    Person p("John", 30);
    p.sayHello(); // calls the sayHello() method of the Person object p
    
    return 0;
}

```
><img src="https://media.licdn.com/dms/image/C4D12AQHk1I-XJxqg4g/article-inline_image-shrink_1000_1488/0/1576765668721?e=1687996800&v=beta&t=hXOvXgaByM6b83CcxEZoPzYbyRNJnv136KXves4NQOA" width=250>



#### Overloading
**Definition:** Is a form of polymorphism, it overrides the meaning of an operator. 
**Code Example:**
```
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
  ```
><img src="https://1.bp.blogspot.com/-n--bPpsfELg/Vc89zk-7vJI/AAAAAAAADlI/VgDvSFWc6NE/s400/Difference%2Bbetween%2Bmethod%2Boverloading%2Band%2Boverriding%2Bin%2BJava.gif" width=250>



#### Polymorphism
**Definition:** The ability of objects of different classes to be treated as if they are of the same class, allowing for a single function call to have different behaviors depending on the type of object being used.

**Code Example:**
```
#include <iostream>

class Animal {
public:
    virtual void makeSound() const = 0; // pure virtual function
};

class Dog : public Animal {
public:
    virtual void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    virtual void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animalPtr = nullptr;
    Dog dog;
    Cat cat;
    
    animalPtr = &dog;
    animalPtr->makeSound(); // calls Dog's implementation of makeSound()
    
    animalPtr = &cat;
    animalPtr->makeSound(); // calls Cat's implementation of makeSound()
    
    return 0;
}

```
><img src="https://techvidvan.com/tutorials/wp-content/uploads/sites/2/2020/02/example-of-polymorphism-in-java.jpg" width=250>



#### Public/Private/Protected

> **Definition:** 
> 
> **Code Example:**
```

```
><img src="https://www.scmgalaxy.com/tutorials/wp-content/uploads/2021/10/php5-1.png" width=250>



#### Static

> **Definition:** 
> 
> **Code Example:**
```

```
><img src="https://static.javatpoint.com/images/java-static-keyword1.png" width=250>



#### Virtual

> **Definition:** 
> 
> **Code Example:**
```

```
><img src="https://www.sandordargo.com/assets/img/diamon-inheritance.png" width=250>

