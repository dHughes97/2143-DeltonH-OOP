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
> **For example:** 
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

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Composition

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Constructor

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Encapsulation

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Friends

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Inheritance

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Instance Variable

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Member Variable

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Method

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Multiple Inheritance

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Object

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Overloading

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



#### Polymorphism

> This is your definition of what a class is. Using images is A-ok. For example: 
>
><img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/722c82aff075a14313be7fa7463f7fedad151a0a.png" width=250>



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

