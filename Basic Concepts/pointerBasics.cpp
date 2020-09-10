//
//  pointerBasics.cpp
//  companiesTestPractice
//
//  Created by Bilal Butt on 20/08/2020.
//  Copyright © 2020 Bilal Butt. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    //              arr 1 2 3 4 5
    int arr[] = {1,2,3,4,5,6}; //len =  6
//    cout << arr << endl;
//    cout << *arr  << endl;
//    cout << (*arr+1) << endl;
//    cout << *(arr-2) << endl;
//    cout << (*arr-3) << endl;
    
    cout << "Original\n";
    cout << *(arr+5) << endl;
    cout << "\nWith Minus Operator\n";
     // I think first it is getting arr[0] = 1, then de-referencing it.
    // Then subtracting int(4) from it. Thus it is resulting -3.
    // On int(5), it is resulting -4. It confirms.
    // Note!!! Remeber it is subtracting the specified number after minus(-) operator,
    // Not the value from array.
    cout << *(arr-5) << endl;
    cout << *(arr)-5 << endl;
    cout << (*arr-5) << endl;
    cout << "\nWith Addition Operator\n";
    cout << *(arr+5) << endl;
    cout << *(arr)+5 << endl;
    cout << (*arr+5) << endl;
    
//    cout << (*arr+5) << endl;
//    cout << *(arr+6) << endl; //Here junk started printing
//    cout << *(arr+7) << endl;
//    cout << *(arr+8) << endl;
}
