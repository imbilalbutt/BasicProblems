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
 This is a code in which all one class have an object
 of other class. But There is no inheritence among them.
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

class B{
    /*Case 1*/
    A a;
//    A a2 ;
    /*Case 2*/
//     Nothing (no object of other class)
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

class C{
    /* Case 1  */
//    A a;
//    A *a = new A(); // This prints out constructor of A().
//    A *a; // But this does not

    /* Case 2  */
    B b;
    B b2;

    /* Case 3  */
//        A a;
//        B b;
public:
    C(){
//        int *i;
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
