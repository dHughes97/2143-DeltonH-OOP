
/*****************************************************************************
*                    
*  Author:           Prof. Griffin (Commented by Delton Hughes)
*  Email:            dlhughes0129@,y.msutexas.edu
*  Label:            A03
*  Title:            Proper Program Commenting
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Description:
*        This program
* 
*  Usage:
*        how to use the program if necessary
* 
*  Files:   main.cpp
*           README.md
*****************************************************************************/
#include <iostream>

using namespace std;

/**
 * Class Name: CircularArrayQue
 * 
 * Description:
 *      
 * 
 * Public Methods:
 *      -void      Push
 *      -int       Pop
 * 
 * Private Methods:
 *      -bool     Full
 * 
 * Usage: 
 * 
 *      - examples of how
 *      - to use your class 
 *      
 */
class CircularArrayQue {
private:
    int *Container;   //creates a container pointer
    int Front;        //variable int created for front 
    int Rear;         //variable int created for back 
    int QueSize;      // items in the queue
    int CurrentSize;  //check cureent size of queue

    /**
     * Private : init
     * 
     * Description:
     *      -allows for size of array to be passed through
     * 
     * Params:
     *      - int size  : int named size default value 0 
     * 
     * Returns:
     *      - returns nothing is void
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;      //setting to 0 
        QueSize = size;                      //set size=QueueSize
    }

    
    /**
     * Private : Full
     * 
     * Description:
     *      Checks to see if CurrentSize is equal to QueSize
     * 
     * Params:
     *      - no params
     * 
     * Returns:
     *      - bool :truly returns if CurrentSize 
     *        equals Quesize (T or F)
     */
    bool Full() {
        return CurrentSize == QueSize;  //return if bot Size vars are equal  
    }

public:

    
    /**
     * Public : CircularArrayQue
     * 
     * Description:
     *      -allocating default size of array 
     * 
     * Params:
     *      - no params
     * 
     * Returns:
     *      - Returns nothing is a constructor
     */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }
    
    /**
     * Public : Push
     * 
     * Description:
     *      -pushes an integer in the back of the queue
     *      while also incrementing CurrentSize count
     * Params:
     *      - int item : creates an int named item
     * 
     * Returns:
     *      - Returns nothing is void
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;      //item goes to back
            Rear = (Rear + 1) % QueSize; //add one to rear
            CurrentSize++;               //Increment Counter
        } else {                         //else if Full
            cout << "FULL!!!!" << endl;  
        }
    }
    
    /**
     * Public: Pop
     * 
     * Description:
     *      Gets rid of front of the queue while 
     *       also decrementing CurrentSize
     * Params:
     *      -no params
     * 
     * Returns:
     *      - Returns an integer(number)
     */
    int Pop() {
        int temp = Container[Front];    //temp pops front
        Front = (Front + 1) % QueSize;  
        CurrentSize--;                  //Decremented counter
        return temp;                    
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {

    CircularArrayQue C1(5); //Creating a Queue of 5 called C1

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}