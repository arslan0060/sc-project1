//
//  nest.cpp
//  tay
//
//  Created by Arslan Memon on 8/28/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//

#include <stdio.h>
#include "matrix.hpp"
static double nest(Matrix &a, double x)
{
    int n=a.Cols();// sets n to the number of columns there are in matrix a
    double p=a(n-1);//last coefficient is assigned to p
    for (int i=n-2;i>=0;i--)//LOOP multiply p by x and add the previous coefficient
    {
        
        p*=x;
        p+=a(i);
    }
    return p;
}