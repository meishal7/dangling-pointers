/*
main.cpp This program demonstrates the examples of dangling pointers.
Author: Elena Mudrakova
Module: 3
Project: Lab 3

Algorithm:
Before main()
1.  #include <iostream>
2. Include functions prototypes. 
In main()
1. Declare int *ptr, *notUsed
2. Call first(&ptr)
3. Declare int value = *ptr
4. Print out the value
5. Call second(&notUsed)
6. value = *ptr;
7. Print out the value
8. Call ptr = third()
9. Print out ptr and *ptr
10. *ptr = 109;
11. Call fourth();
12. Create for loop and call fifth() several times
After main()
1. Declare void first(int **ptrToPtr)
    1. Declare n =5
    2. *ptrToPtr = &n
2. Declare void second(int **notUsedPtr)
    1. int z = 6
3. Declare int *third()
    1. int n = 29
    2. return &n
4. Declare void fourth()
    1. int x
    2. cout value of x
5. Declare void fifth()
    1. static int *array = new int[10000], total =0
    2. Create for loop
        In for loop:
        1. array[i] = i
        2. total += array[i]
    After for loop:    
    1. cout total
    2. delete []array;
*/
#include <iostream>
using namespace std;

//Prototypes
void first(int **ptrToPtr);
void second(int **dummy);
int *third();
void fourth();
void fifth();

int main() {
  int *ptr, *notUsed;
  
  // Call the first(&ptr). After function stops ptr will become a dangling pointer because it will point to de-allocated memory.
  first(&ptr);
  //Now ptr is dangling pointer
  int value = *ptr; 
  cout << "After first(&ptr) the *ptr now is " << value << endl;
  
  // Call second(&notUsed) passing the parametr that is never used. Ptr is still dangling pointer as it's value changed after second() call even though it's never accessed directely through the second() function.
  second(&notUsed);
  value = *ptr;
  cout << "After second(&notUsed) the *ptr now is " <<  value << endl;
  
  // Call third(), return pointer to a local var from function
  ptr = third();
  cout << "After third() returned address is " << ptr << endl;
  cout << "The value in that address is " << *ptr << endl;
  
  // Call fourth() and see if the value for local var can be set outside of the function
  *ptr = 109;
  fourth();

  // Call the fifth(). Accessing de-allocated memory
  for(int i= 0; i<10; i++){
    fifth();
  }

  

  return 0;
}

//Function declaration
void first(int **ptrToPtr){
  int n = 5;
  *ptrToPtr = &n;
  //*ptrToPtr = nullptr;
  
}

void second(int **notUsedPtr){
  int z = 6;
}

int *third(){
  int n = 29;
  return &n;
}

void fourth(){
  int x;
  cout <<"In fourth() the value of x is " << x << endl;
}

void fifth(){
  static int *array = new int[10000], total =0;
  for(int i = 0; i < 10000; i++){
    array[i] = i;
    total += array[i];
  }
  cout << "Total is " << total << endl;
  delete []array;
}