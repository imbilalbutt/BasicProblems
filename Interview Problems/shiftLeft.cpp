//
//  shiftLeft.cpp
//  companiesTestPractice
//
//  Created by Bilal Butt on 13/09/2020.
//  Copyright © 2020 Bilal Butt. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

void shift_left_by_one(int arr[], int length){
    for (int i =0;i< length-1;i++){
        arr[i] = arr[i+1];
    }
    arr[length-1] = 0;
}

void shift_left_by_n_times(int arr[], int lenght, int n_times){
    for (int i = 0; i < n_times;i++){
        shift_left_by_one(arr, lenght);
    }
}

int main(){
    int arr[] = {1,2,3,4};
    int length = 4;
    int n_times = 1;
    //    rotate_left_by_one(arr, length);
    shift_left_by_n_times(arr, length, n_times);
    
    // print array
    for (int i = 0; i < length;i++) {
        cout << arr[i] << " ";
    }
}

