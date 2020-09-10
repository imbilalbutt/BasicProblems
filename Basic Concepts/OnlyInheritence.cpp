//
//  main.cpp
//  companiesTestPractice
//
//  Created by Bilal Butt on 15/06/2020.
//  Copyright © 2020 Bilal Butt. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

/*
There is specifically Only inheritence among them.
 They have no association among them, meaning they
 don't have private objects (as attributes) of other class.
 */

class A{
public:
    A(){
        cout << "\nConstructor Called A()";
    }
    ~A(){
        cout << "\nDeconstructor called ~A()";
    }
};

class B: public A{
public:
    B(){
        cout << "\nConstructor Called B()";
    }
    ~B(){
        cout << "\nDeconstructor called ~B()";
    }
};

/*Case 1*/
// class C: public A{
/*Case 2*/
class C: public B{
public:
    C(){
        cout << "\nConstructor Called C()";
    }
    ~C(){
        cout << "\nDeconstructor called ~C()";
    }
};

//void A(){
//    printf("A");
////    A();
//
//};

int main(int argc, const char * argv[]) {
    //    // insert code here...
    //    std::cout << "Hello, World!\n";
    //    return 0;
    
    
    C c =  C();
    //    int n = 9, div = 0;
    //    div = n/0;
    //    printf("result = %d",div);
    
    //    int a,b,c;
    //    c = a+b;
    
    
    //    m();
    //    void m()
    //    {
    //        cout << "m";
    //    }
    
    //    void foo();
    //    cout << "1";
    //    foo();
    //    C c ;
    
    return 0;
}

//void foo(){
//    cout << "2 ";
//}
