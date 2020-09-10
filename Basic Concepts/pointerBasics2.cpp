//
//  pointerBasics2.cpp
//  companiesTestPractice
//
//  Created by Bilal Butt on 31/08/2020.
//  Copyright © 2020 Bilal Butt. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

typedef struct { float x; float y; } C;

int main(){
//    int val = 5;
//    int* pt;
//    pt = &val;
//
//    cout << *pt;
    
//    float val = 5.5;
//    float* pt;
//    pt = &val;
//
//    cout << *pt;
    
    C c;
    c.x = 10.5;
    c.y = 10.5;

    C* zpt;
    zpt= &c;
//    cout << (*zpt).x; // equivalent to zpt-> x
    cout << zpt->x;
}
