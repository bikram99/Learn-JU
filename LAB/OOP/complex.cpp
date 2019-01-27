#include<iostream>
#include<ostream>
#include<istream>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

class Complex
{
    
    private:
        double real;
        double imaginary_;
        
    
    public:
        
        Complex()
        {
            real=0.0;
            imaginary_=0.0;
            
         }
	Complex(double r,double imag)
	{
		real=r;
		imaginary_=imag;
	}

 
	friend ostream& operator<<(ostream& o,const Complex& c1)
	{
		if(c1.real!=0 && c1.imaginary_!=0)
			o<<c1.real<<" + i( "<<c1.imaginary_<<")\n";
		else if(c1.imaginary_==0)
			o<<c1.real;
		else if(c1.real==0)
			o<<"i( "<<c1.imaginary_<<")";
	
		return o;
	}

	friend istream& operator>>(istream& in,Complex& c1)
	{
	
	

		char temp;
		bool minus = false;
		in>>c1.real;
		temp = in.get();

		if(temp == '-')
			minus = true;
		else if(temp == '+')
			minus = false;
		else if(temp=='\n')
			return in;
		else {
			c1.real = 0;
			while(in.get() != '\n');
			return in;
		}
		

		temp=in.get();
		if(temp != 'i') {
			c1.real = 0;
			cout<<"Wrong input format\n";
			while(in.get() != '\n');
			return in;
		}

		in >> c1.imaginary_;


		if(minus)
			c1.imaginary_ *= -1;

		return in;
	}


         
	friend Complex operator+(const Complex& c1,const Complex& c2)
	{
		Complex c3(c1.real + c2.real,c1.imaginary_+c2.imaginary_);

		return c3;

	}

	friend Complex operator-(const Complex& c1,const Complex& c2)
	{
		Complex c3(c1.real-c2.real,c1.imaginary_ - c2.imaginary_);
		return c3;	
	}


                  
};


int main()
{
	cout<<"Menu for Complex no operations:\n";
	cout<<"1.Insert Value.\n";
	cout<<"2.Add.\n";
	cout<<"3.Substract.\n";
	cout<<"4.Exit.\n";

	while(true)
	{
		int choice;
		Complex c1,c2,c3;

		cout<<"Enter choice:";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"Enter the complex no\n";
				cin>>c1;
				cout<<"Input successfull\n"<<c1<<"\n";
				break;
			case 2:
				cout<<"Complex no 1\n";
				cin>>c1;
				cout<<"Complex no 2\n";
				cin>>c2;
				c3=c1+c2;
				cout<<"Addition Successfull.\nResult= "<<c3<<"\n";
				break;
			case 3:
				cout<<"Complex no 1\n";
				cin>>c1;
				cout<<"Complex no 2\n";
				cin>>c2;
				c3=c1-c2;
				cout<<"Substraction Successfull.\nResult= "<<c3<<"\n";
				break;	

			case 4:
				break;
			default:
				cout<<"Wrong choice\n";
		}

		if(choice==4)
			break;

	}

	return 0;

}


				



