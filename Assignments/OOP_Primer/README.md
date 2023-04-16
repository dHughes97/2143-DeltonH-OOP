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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Frealpython.com%2Finheritance-composition-python%2F&psig=AOvVaw1dyIIPoREuGEC2dz6pUARd&ust=1679077529152000&source=images&cd=vfe&ved=0CA8QjRxqFwoTCKCfsK-J4f0CFQAAAAAdAAAAABAE" width=250>



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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.geeksforgeeks.org%2Fconstructors-c%2F&psig=AOvVaw3vRN-QyBBfNXpRKAppOmE2&ust=1679077661190000&source=images&cd=vfe&ved=0CA8QjRxqFwoTCJjrne6J4f0CFQAAAAAdAAAAABAE" width=250>



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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fmedium.com%2F%40kamilmasyhur%2Fa-principle-of-object-oriented-design-79b9bfefd446&psig=AOvVaw3jIRTlLalWXcA7d43KS1VC&ust=1681690602051000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCNiFzOmPrf4CFQAAAAAdAAAAABAE" width=250>



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


><img src="https://www.google.com/imgres?imgurl=https%3A%2F%2Fmedia.geeksforgeeks.org%2Fwp-content%2Fuploads%2F20220802105339%2FFriendFunctioninC-660x328.png&tbnid=eGdhXh4GMno0RM&vet=12ahUKEwjSy4PmkK3-AhUrN94AHTzUBV4QMygBegUIARC8AQ..i&imgrefurl=https%3A%2F%2Fwww.geeksforgeeks.org%2Ffriend-class-function-cpp%2F&docid=FyVwkkJos8SXGM&w=660&h=328&q=friends%20oop%20definition&ved=2ahUKEwjSy4PmkK3-AhUrN94AHTzUBV4QMygBegUIARC8AQ" width=250>



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
><img src="https://www.google.com/imgres?imgurl=https%3A%2F%2Fupload.wikimedia.org%2Fwikipedia%2Fcommons%2Fthumb%2Fb%2Fb6%2FMethod_overriding_in_subclass.svg%2F220px-Method_overriding_in_subclass.svg.png&tbnid=7EXLMgePqGyJlM&vet=12ahUKEwj1uJP_ka3-AhX4Kt4AHUz-A94QMygAegUIARDCAQ..i&imgrefurl=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FInheritance_(object-oriented_programming)&docid=FKwTtST1_NLePM&w=220&h=306&q=inheritance%20oop%20definition&ved=2ahUKEwj1uJP_ka3-AhX4Kt4AHUz-A94QMygAegUIARDCAQ" width=250>



#### Instance Variable
**Definition:**Has a separate copy or instance in each of the its instances. It is non-static.
```
class Person {
private:
    std::string name;
    int age;
}
```

><img src="https://www.google.com/imgres?imgurl=https%3A%2F%2Fwww.w3resource.com%2Fw3r_images%2Fjava-class-image.png&tbnid=sxfXnGymFEgdZM&vet=12ahUKEwjd0Kufk63-AhVQH94AHfW1CvkQMygAegUIARC_AQ..i&imgrefurl=https%3A%2F%2Fwww.w3resource.com%2Fjava-tutorial%2Fjava-class-methods-instance-variables.php&docid=V5DeKz6Xs68FgM&w=539&h=280&q=instance%20variable%20oop%20definition&ved=2ahUKEwjd0Kufk63-AhVQH94AHfW1CvkQMygAegUIARC_AQ" width=250>



#### Member Variable
**Definition:**is a variable assigned to its class which is accessible only to methods within the class and inheritated classes or friended methods.
```
class Person {
private:
    std::string name;
    int age;
}
```

><img src="https://www.google.com/imgres?imgurl=https%3A%2F%2Fwww.w3resource.com%2Fw3r_images%2Fjava-class-image.png&tbnid=sxfXnGymFEgdZM&vet=12ahUKEwir7PGMlK3-AhW_LN4AHWTADwIQMygAegUIARDKAQ..i&imgrefurl=https%3A%2F%2Fwww.w3resource.com%2Fjava-tutorial%2Fjava-class-methods-instance-variables.php&docid=V5DeKz6Xs68FgM&w=539&h=280&q=member%20variable%20oop%20definition&hl=en&ved=2ahUKEwir7PGMlK3-AhW_LN4AHWTADwIQMygAegUIARDKAQ" width=250>



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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fsoftwareengineering.stackexchange.com%2Fquestions%2F342040%2Foop-methods-contained-in-objects&psig=AOvVaw2AUBJiC1ypNvB3hElQy1rE&ust=1681691780419000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCOjGvZuUrf4CFQAAAAAdAAAAABAE" width=250>



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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.techtarget.com%2Fwhatis%2Fdefinition%2Fmethod&psig=AOvVaw2X8QpaPZqGmZpJ2wqSJvKJ&ust=1681691832710000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCNC2jtSVrf4CFQAAAAAdAAAAABAE" width=250>



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
><img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.techtarget.com%2Fwhatis%2Fdefinition%2Fmethod&psig=AOvVaw2X8QpaPZqGmZpJ2wqSJvKJ&ust=1681691832710000&source=images&cd=vfe&ved=0CBAQjRxqFwoTCNC2jtSVrf4CFQAAAAAdAAAAABAE" width=250>



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
><img src="https://www.google.com/imgres?imgurl=https%3A%2F%2Fstatic.javatpoint.com%2Fcpp%2Fimages%2Fcpp-overloading.png&tbnid=iT4r0qGwYRRjSM&vet=12ahUKEwiVmuDwlq3-AhVawMkDHX98DBUQMygGegUIARDTAQ..i&imgrefurl=https%3A%2F%2Fwww.javatpoint.com%2Fcpp-overloading&docid=_p40B1KHnKsFtM&w=303&h=204&q=overloading%20oop%20definition&ved=2ahUKEwiVmuDwlq3-AhVawMkDHX98DBUQMygGegUIARDTAQ" width=250>



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
><img src="https://www.google.com/imgres?imgurl=https%3A%2F%2Fi.ytimg.com%2Fvi%2FA5sp7i8NXWg%2Fmaxresdefault.jpg&tbnid=195y_VtlkGhvLM&vet=12ahUKEwiwy_qWl63-AhXkIt4AHfK4CZUQMygEegUIARDiAQ..i&imgrefurl=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DA5sp7i8NXWg&docid=JS7_3EPu4j16IM&w=1280&h=720&q=polymorphism%20in%20oop&ved=2ahUKEwiwy_qWl63-AhXkIt4AHfK4CZUQMygEegUIARDiAQ" width=250>



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

