#include<iostream>
#include<string>

class Complex
{
    
    private:
        double real;
        double imaginary;
        
    
    public:
        
        Complex()
        {
            real=0.0;
            imaginary=0.0;
            
         }
         
         friend ostream & operator << (ostream &out, const Complex &c); 
         friend istream & operator >> (istream &in,  Complex &c); 
         
         void get_value(double Real,double Imaginary)
         {
            real=Real;
            imaginary=Imaginary;
         }
         
         void display()
         {
            cout<<real<<"+"<<imaginary<<"i \n";
            
         }
         
         Complex operator +(Complex &number)
         {
            Complex num1;
            num1.real=this->real + number.real;
            num1.imaginary=this->imaginary + number.imaginary;
            return (num1);
        }
        Complex operator -(Complex &number)
        {
            Complex num1;
             num1.real=this->real - number.real;
            num1.imaginary=this->imaginary - number.imaginary;
            return (num1);
         }
         
        }
        
        istream & operator >>(istream &in,Complex &num)
        {
            cout<<"Enter the complex number";
            string cpx_no;
            in>>cpx_no;
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
             
    
