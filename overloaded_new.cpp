#include <iostream>

void *operator new (size_t);                                            //Prototype       //Overwrited new operator 
void *operator new (size_t, char);                                     //Prototype       //Overloaded new operator (character)
void *operator new (size_t, int);                                     //Prototype       //Overloaded new operator (int)
void *operator new[](size_t);                                        //Prototype       //Overloaded new [] operator
void operator delete (void *);                                      //Prototype       //Overwrited delete operator
void operator delete[] (void *);                                   //Prototype       //Overloaded delete [] operator

int main () {
   
   int *ptr = new int;
   delete ptr;
   ptr = nullptr;
   int *ptr1 = new(13) int;
   std::cout << "ptr dereferenced value is " << *ptr1 << std::endl;
   delete ptr1;
   ptr1 = nullptr;
   char *ch = new('b') char;
   std::cout << "ch dereferenced value is " << *ch << std::endl;
   delete ch;
   ch = nullptr;
   int *ptr_array = new int[5];
   delete [] ptr_array;
   ptr_array = nullptr;

return 0;
}
 
void *operator new (size_t size) {                                                    //Overwrited new operator
    void *ptr = malloc(size);
    if (ptr ==NULL) {
       std::cout << "Allocation failed \nFATAL ERROR: ABORTION" << std::endl;
       exit(1);
    } 
    std::cout << "Overwrited new operator is called" << std::endl;
return ptr;
}

void *operator new (size_t size, char ch) {                                         //Overloaded new operator (character)
    char *ptr = (char*) malloc(size);
    if (ptr == NULL) {
       std::cout << "Allocation failed \nFATAL ERROR: ABORTION" << std::endl;
       exit(1);
    }
    *ptr = ch;
    std::cout << "Overloaded new operator is called (char)" << std::endl;
return ptr;
}

void *operator new (size_t size, int num) {                                           //Overloaded new operator (int)
    int *ptr = (int*) malloc(size);
    if (ptr == NULL) {
       std::cout << "Allocation failed \nFATAL ERROR: ABORTION " << std::endl;
       exit(1);
    }
    *ptr = num;
    std::cout << "Overloaded new operator is called (int)" << std::endl;
return ptr;
}

void *operator new[](size_t size) {                                                   //Overloaded new [] operator
    void *ptr = malloc(size);
    if(ptr == NULL) {
       std::cout << "Allocation failed \nFATAL ERROR: ABORTION " << std::endl;
       exit(1);
    }
    std::cout << "Overloaded new [] operator is called" << std::endl;
    return ptr;
}

void operator delete (void *ptr) {                                                    //Overwrited delete operator
    std::cout << "Overwrited delete operator is called" << std::endl;
    free(ptr);
}

void operator delete[] (void *ptr_array) {                                            //Overloaded delete [] operator
    std::cout << "Overloaded delete [] operator is called" << std::endl;
    free(ptr_array);
}