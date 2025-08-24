/*Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.*/

/*Ans: Shallow copy only copies the pointer address and creates a shared memory between objects, so changing
a value will have its effect on all thr objects sharing the same memory whereas deep copy creates another copy by 
copying the value of the object as well, so in that way each object could have its own memory and change in one would not 
affect the other.
*/

#include <iostream>
using namespace std;

class Box {  
public:
	int *value;
	Box(int a){
		value=new int(a);
	}
    Box(const Box& a) {
        value = new int(*a.value);
    }
    Box& operator=(const Box& a) {            
        value = new int(*a.value);
        return *this;
    }
    ~Box() {
        delete value;
    }
    void setValue(int v) {
        *value = v;
    }
};

int main() {
    Box b1(10);
    Box b2 = b1;  
    Box b3(0);             
    b3 = b1;
    cout << "b1: "<<*b1.value<<endl;
    cout << "b2: "<<*b2.value<<endl;
    cout << "b3: "<<*b3.value<<endl;
}
