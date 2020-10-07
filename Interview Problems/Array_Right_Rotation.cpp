//
//  rotateRight.cpp
//  companiesTestPractice
//
//  Created by Bilal Butt on 12/09/2020.
//  Copyright © 2020 Bilal Butt. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

    // 0 1 2 3
//0  1  2 3 4
//1  4 1  2 3
//2  3 4 1  2
//3  2 3 4  1

void rotate_right_by_one(int arr[], int length){
    int temp = arr[length-1];
    for (int i = length-1; i > 0;i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

void rotate_right_by_n_times(int arr[], int length, int n_times){
    for (int i =0; i < n_times;i++){
        rotate_right_by_one(arr, length);
    }
}

int main(){
    int arr[] = {1,2,3,4};
    int length = 4;
    int n_times = 1;
    rotate_right_by_n_times(arr, length, n_times);
    
    // print array
    for (int i = 0; i < length;i++) {
        cout <<  arr[i] << " ";
    }
}
