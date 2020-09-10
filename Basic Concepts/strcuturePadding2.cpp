
  strcuturePadding2.cpp
  companiesTestPractice

  Created by Bilal Butt on 09/09/2020.
  Copyright © 2020 Bilal Butt. All rights reserved.


#include <stdio.h>
#include <string.h>

/*  Below structure1 and structure2 are same.
 They differ only in member's allignment */

/*
 HOW TO AVOID STRUCTURE PADDING IN C LANGUAGE?

 #pragma pack ( 1 ) directive can be used for arranging memory for structure members very next to the end of other structure members.
 VC++ supports this feature. But, some compilers such as Turbo C/C++ does not support this feature.
 Please check the below program where there will be no addresses (bytes) left empty because of structure padding.
 */


#pragma pack(1)
struct structure1
{
    int id1;
    int id2;
    char name;
    char c;
    float percentage;
};

struct structure2
{
    int id1;
    char name;
    int id2;
    char c;
    float percentage;
};

int main()
{
    struct structure1 a;
    struct structure2 b;

    printf("size of structure1 in bytes : %d\n", sizeof(a));
    printf ( "\n   Address of INT id1        = %u", &a.id1 );
    printf ( "\n   Address of INT id2        = %u", &a.id2 );
    printf ( "\n   Address of CHAR name       = %u", &a.name );
    printf ( "\n   Address of CHAR c          = %u", &a.c );
    printf ( "\n   Address of FLOAT percentage = %u", &a.percentage );

    printf("   \n\nsize of structure2 in bytes : %d\n", sizeof(b));
    printf ( "\n   Address of INT id1        = %u", &b.id1 );
    printf ( "\n   Address of CHAR name       = %u", &b.name );
    printf ( "\n   Address of  INT id2        = %u", &b.id2 );
    printf ( "\n   Address of CHAR c          = %u", &b.c );
    printf ( "\n   Address of FLOAT percentage = %u", &b.percentage );
    getchar();
    return 0;
}
