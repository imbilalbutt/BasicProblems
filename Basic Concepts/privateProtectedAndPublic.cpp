//
//  privateProtectedAndPublic.cpp
//  companiesTestPractice
//
//  Created by Bilal Butt on 27/08/2020.
//  Copyright © 2020 Bilal Butt. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class A{
private:
    int prvt;
protected:
    int protec;
public:
    int publc;
    
    A(){
        cout << "\nA() Constructor called.\n";
        prvt = 0;
        protec = 0;
        publc = 0;
    }
    
    A(int pr, int proc, int pbc){
        prvt = pr;
        protec = proc;
        publc = pbc;
    }
    
    virtual void printInfo(){
        cout << "\nA() prvt = " << prvt;
        cout << "\nA() protec = " << protec;
        cout << "\nA() publc = " << publc;
    }
};

class Private: private A{
public:
    Private(){
        cout << "\nPrivate() constructor called.\n";
        cout << "\nIn Private(): publc = " << ++publc;
        cout << "\nIn Priavte(): protec  = " << ++protec;
        //        cout << "\nIn Priavte(): prvt = " << prvt; // private is not accessible in PRIVATE inheritance.
    }
};

class Protected: protected A{
public:
    Protected(){
        cout << "\nProtected() constructor called.\n";
        cout << "\nIn Protected(): publc = " << ++publc;
        cout << "\nIn Protected(): protec  = " << ++protec;
        //        cout << "\nIn Protected(): prvt = " << prvt; // private is not accessible in PROTECTED inheritance.
    }
};

class Public : public A{
public:
    Public() {
        cout << "\nPublic() Constructor called.\n";
        cout << "\nIn Public(): publc = " << ++publc;
        cout << "\nIn Public(): protec  = " << ++protec;
        //        cout << "\nIn Public(): prvt = " << prvt; // private is not accessible in PUBLIC inheritance.
    }
};



int main(){
    ////    // Case 1: with Class()
    //    A a = A();
    //    Private pvt = Private();
    //    Protected pro =  Protected();
    //    Public pbl = Public()
    
    ///    // Case 2: with new Class()
    //        A a = new A();
    //        Private pvt = new Private();
    //        Protected pro =  new Protected();
    //    Public pbl = new Public();
    
    ////    // Case 3
//    A a;
    Private pvt;
    Protected pro;
    Public pbl;
    
    return 0;
}
