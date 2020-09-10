//
//  Objects&Inheritence.cpp
//  companiesTestPractice
//
//  Created by Bilal Butt on 20/08/2020.
//  Copyright © 2020 Bilal Butt. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

/*
 This is a code in whichm one class have an object
 of other class. And There is inheritence among them.
 In this case, multilevel inheritence is used.
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
    A a;
public:
    B(){
        cout << "\nBefore creating B()";
        cout << "\nConstructor Called B()";
        cout << "\nAfter creating B()\n";
    }
    ~B(){
        cout << "\nDeconstructor called ~B()";
    }
};
/*Case 1*/
// class C: public A{

/*Case 2*/
class C: public B{
    /* Case 1  */
    //    A a;
    
    /* Case 2  */
    B b;
    
    /* Case 3  */
    //    A a;
    //    B b;
public:
    C(){
        cout << "\nBefore creating C()";
        cout << "\nConstructor Called C()";
        cout << "\nAfter creating C()\n";
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
