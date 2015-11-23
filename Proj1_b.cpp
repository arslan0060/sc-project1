//
//  Proj1_b.cpp
//  tay
//
//  Created by Arslan Memon on 9/10/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//
#include <iostream>
using namespace std;
#include "matrix.hpp"
#include <math.h>
#include <tgmath.h>
double relativeError(double h)//calculate relative error using formula given
{
    double sdpfa = (pow(3+h,-3)-pow(3,-3))/h;//δ+f(a) = f(a + h) − f(a)/f(h),a=3
    return ((-3*pow(3, -4))-sdpfa)/(-3*pow(3, -4));//r= f'(a)-δ+f(a)/f'(a), a=3
}
double upperBound(double h)//upper bound for error
{
    double c1=fabs((12*pow(3,-5))/(-6*pow(3,-4)));//c1=|f''(a)/2f'(a)|
    double c2=fabs((pow(3, -3)*pow(2, -52))/(-3*pow(3,-4)));//|c2=f(a)edp/f'(a)
    return (c1*h)+(c2/h);

}
int main(int argc, const char * argv[]) {

    Matrix n=Linspace(1, 52, 52);//evenly creates a matrix of 52 evenly divisible numbers
    Matrix h(52,1);//h=2^-n fill the matrix with for loop
    for (double i=0; i<n.Size(); i++) {
        h(i)= pow(2, -1*n(i));
    }
    Matrix r(52,1);//relative error matrix
    Matrix R(52,1);//upper bound matrix
    //calculate r and R
    for (double i=0; i<r.Size(); i++) {
        r(i)= relativeError(h(i));
    }
    for (double i=0; i<R.Size(); i++) {
        R(i)= upperBound(h(i));
    }
// write matrices
    r.Abs();
    R.Abs();
    h.Write("h.txt");
    n.Write("n.txt");
    r.Write("r.txt");
    R.Write("Rcap.txt");
 //r and R are treated as the same file, so stored R as Rcap
};