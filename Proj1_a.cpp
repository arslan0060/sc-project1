//
//  main.cpp
//  tay
//
//  Created by Arslan Memon on 8/27/15.
//  Copyright (c) 2015 Arslan. All rights reserved.
//
//this belongs to Arslan Memon

#include <iostream>
#include "nest.cpp"
#include <math.h>
#include <tgmath.h>
double factorial(double x)//calculates factorial
{double fact=1;
  if(x==0)
      return 1;
   while (x!=0)
   {
       fact*=x;
       x--;
   }
    return fact;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    double coeff[13];//array of coefficients for taylor polynomial of cos(x)
    bool neg=false;//if coefficient is supposed  to be negative, then true
    for (int i=0.0; i<13; i++) {//assigns coefficients to array
        if(i%2==0)
        {if(!neg)
        {
            coeff[i]=(double)(1.0/factorial(i));
            neg=true;
        }
            else
            {         coeff[i]=(double)(-1.0/factorial(i));
            neg=false;
            }
        }
        else{
            coeff[i]=0;
        }
        
    }
    
  
    Matrix z=Linspace(-3, 3, 601);//creates matrix with  601 evenly div numbers between -3 and 3
     Matrix p4coeff(1,5,coeff);//matrix with first 4 taylor coefficients
    
    Matrix p4(1,601);//matrix with result for 4th degree polynomial evaluated at z
    for (int i=0;i<601;i++)
    {
        p4(i)=nest(p4coeff,z(i));
    }
    p4.Write("p4.txt");//wriete results to text  file
    
    //same as above for 8th degree polynomial
    Matrix p8coeff(1,9,coeff);
    Matrix p8(1,601);
    for (int i=0;i<601;i++)
    {
        p8(i)=nest(p8coeff,z(i));
    }
    p8.Write("p8.txt");
    
    //same as above for 12th degree polynomial
    Matrix p12coeff(1,13,coeff);
    Matrix p12(1,601);
    for (int i=0;i<601;i++)
    {
        p12(i)=nest(p12coeff,z(i));
    }
    p12.Write("p12.txt");
    
    // all points are evaluated at cos(x)
    Matrix f(1,601);
    for (int i=0;i<601;i++)
    {
        f(i)=cos(z(i));
    }
    f.Write("f.txt");
    
    //calculate relative error for the three taylor polynomials
    Matrix err4(1,601);
    for (int i=0;i<601;i++)
    {
        err4(i)=cos(z(i))-p4(i);
    }
    err4.Abs();
    err4.Write("err4.txt");
    Matrix err8(1,601);
    for (int i=0;i<601;i++)
    {
        err8(i)=cos(z(i))-p8(i);
    }
    err8.Abs();
    err8.Write("err8.txt");
     Matrix err12(1,601);
    for (int i=0;i<601;i++)
    {
        err12(i)=cos(z(i))-p12(i);
    }
    err12.Abs();
    err12.Write("err12.txt");
    z.Write("z.txt");
    }
