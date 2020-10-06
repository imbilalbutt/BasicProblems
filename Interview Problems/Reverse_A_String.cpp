//
//  reverseString.cpp
//  String Coding Problem
//
//  Created by Bilal Butt on 16/09/2020.
//  Copyright © 2020 Bilal Butt. All rights reserved.
//
//* Given a string, you need to reverse each word of it.
//
//** You need to first parse with respect to space (a delimeter) then you need to
//** reverse each and every word.
//

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;


string reverseWord(string &word){
  // This function contains some memory leaks.
    int j =int(word.length()-1);
    for (int i =0; i < word.length()/2;i++){
        swap(word[i], word[j]);
        j--;
    }
    cout << word;
    return word;
}

char* reverseWord(char* word){
    int lenght = int(strlen(word));
    cout << "\nLenght = " << lenght;
    int j = lenght-1;
    for (int i =0; i < lenght / 2;i++){
        swap(word[i], word[j]);
        j--;
    }
    return word;
}

int main(){
    char str[] = "This a sample string.";
    char delim[] = " .";
    
    char *token = strtok(str,delim);
    while (token) {
        cout << "Original Token = " << token;
        char* rvr = reverseWord(token);
        cout << "\nReversed Token = " << rvr << "\n\n";
        token = strtok(NULL,delim);
    }
    return 0;
}
