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

> **Definition:**A class that references one or more objects of other classes in instance variables. 
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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fmedium.com%2F%40kamilmasyhur%2Fa-principle-of-object-oriented-design-79b9bfefd446&psig=AOvVaw0vNSN3YLy3OuH2KDs-H_BS&ust=1681786928088000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCNDPotX2r_4CFQAAAAAdAAAAABAE" width=250>



#### Constructor

> **Definition:**It initializes a newly created object of that type. This could be a copy, default, or even a parameterized constructor. 
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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.geeksforgeeks.org%2Fconstructors-c%2F&psig=AOvVaw21q3nrJo2okdWqCA-jZDFw&ust=1681786996024000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCNDa5fX2r_4CFQAAAAAdAAAAABAE" width=250>



#### Encapsulation

> **Definition:**a class that references one or more objects of other classes in instance variables. 

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
><img src="https://www.google.com/imgres?imgurl=https%3A%2F%2Fi.ytimg.com%2Fvi%2FcWE3StXcEyM%2Fmaxresdefault.jpg&tbnid=8R9K_6UPjyCQzM&vet=12ahUKEwjN_I7A-K_-AhVfMt4AHb8yBPYQMygEegUIARDCAQ..i&imgrefurl=https%3A%2F%2Fviktor-kukurba.medium.com%2Fobject-oriented-programming-in-javascript-4-encapsulation-4f9165cd26f9&docid=_QHVEehau8V6jM&w=1280&h=720&q=encapsulation%20oop%20definition&ved=2ahUKEwjN_I7A-K_-AhVfMt4AHb8yBPYQMygEegUIARDCAQ" width=250>



#### Friends

**Definition:**Is put on a function that allows the method to access private and protected data members. 

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


><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.geeksforgeeks.org%2Ffriend-class-function-cpp%2F&psig=AOvVaw2vZkc7jOsBvDSebG5VC-lx&ust=1681787469221000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCICkvdf4r_4CFQAAAAAdAAAAABAE" width=250>



#### Inheritance

**Definition:**allows us to derive a class from another class, lets then share a set of methods or attributes. 

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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FInheritance_%2528object-oriented_programming%2529&psig=AOvVaw11XjzbkTHgwHr8ml2569-v&ust=1681787499534000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCMiE6eX4r_4CFQAAAAAdAAAAABAE" width=250>



#### Instance Variable
**Definition:**Has a separate copy or instance in each of the its instances. It is non-static.
```
class Person {
private:
    std::string name;
    int age;
}
```

><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.w3resource.com%2Fjava-tutorial%2Fjava-class-methods-instance-variables.php&psig=AOvVaw2EGe5GprTuUuZPik44L4Cd&ust=1681787542590000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCLihsPr4r_4CFQAAAAAdAAAAABAE" width=250>



#### Member Variable
**Definition:**is a variable assigned to its class which is accessible only to methods within the class and inheritated classes or friended methods.
```
class Person {
private:
    std::string name;
    int age;
}
```

><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.simplilearn.com%2Ftutorials%2Fcpp-tutorial%2Foops-concepts-in-cpp&psig=AOvVaw39w9J26suXs68P_TdvVLaM&ust=1681787580022000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCKC3n4z5r_4CFQAAAAAdAAAAABAE" width=250>



#### Method
**Definition:**is a function within a class that manipulates the member variables and/or allows the user to use a the created structure in a variety of ways.
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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.techtarget.com%2Fwhatis%2Fdefinition%2Fmethod&psig=AOvVaw1AIQL8UAswu8QevJcPndCF&ust=1681787625509000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCIji-6H5r_4CFQAAAAAdAAAAABAE" width=250>



#### Multiple Inheritance

**Definition:**Say we have three classes and one is the parent the other is the child and the third is the child of the child. It allows the last child to inherit from the parent of the first child and the original parent. 

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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.geeksforgeeks.org%2Fmultiple-inheritance-in-c%2F&psig=AOvVaw0B9OKeeRCxciSxInMXKG2z&ust=1681787657464000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCPi1lrH5r_4CFQAAAAAdAAAAABAJ" width=250>



#### Object
**Defintion:**the things you think about first in designing a program and they are also the units of code that are eventually derived from the process
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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.c-sharpcorner.com%2FUploadFile%2Fmkagrahari%2Fintroduction-to-object-oriented-programming-concepts-in-C-Sharp%2F&psig=AOvVaw0fkC2WOJhmEOYiZj0Bc-pQ&ust=1681787795958000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCJiyrPP5r_4CFQAAAAAdAAAAABAE" width=250>



#### Overloading
**Definition:**Is a form of polymorphism, it overrides the meaning of an operator. 
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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.javatpoint.com%2Fcpp-overloading&psig=AOvVaw2Zyw83jQ8VZAtFx9JYrVXB&ust=1681787842227000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCLisoIn6r_4CFQAAAAAdAAAAABAE" width=250>



#### Polymorphism
**Definition:** the ability of objects of different classes to be treated as if they are of the same class, allowing for a single function call to have different behaviors depending on the type of object being used.

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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.geeksforgeeks.org%2Fperl-polymorphism-in-oops%2F&psig=AOvVaw0JdRHPcajDs2LdmslnaxGK&ust=1681787883119000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCPjw4pz6r_4CFQAAAAAdAAAAABAE" width=250>



#### Public/Private/Protected

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Static

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Virtual

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>

