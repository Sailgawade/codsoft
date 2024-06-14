#include <iostream>
using namespace std;

float add(float x,float y)
{  
   	return x+y;
}
float subtract(float x,float y) 
{
    return x-y;
}
float multiply(float x,float y) 
{
    return x*y;
}
float divide(float x,float y)
{
    if (y==0) 
	{
        cout<<"Error! Division by zero."<<endl;
        return 0;
    }
    
    return x/y;
}

void calculator() 
{
    int choice;
    float num1,num2;
    
	cout<<"Select operation:"<< endl;
    cout<<" 1. Addition"<< endl;
    cout<<" 2. Subtraction"<< endl;
    cout<<" 3. Multiplication"<< endl;
    cout<<" 4. Division"<< endl;
    
    while (true) 
	{
        cout<<"\nEnter choice from (1/2/3/4): ";
        cin>>choice;
        
        if (choice>=1 && choice<=4) 
		{
            cout<<"\nEnter first number: ";
            cin>>num1;
            cout<<"Enter second number: ";
            cin>>num2;

            switch (choice) 
			{
                case 1:
                    cout<<"\n the addition 0f:" <<num1<<" + "<<num2<<" = "<<add(num1, num2)<<endl;
                    break;
                case 2:
                    cout<<"\n the subtraction 0f:" <<num1<<" - "<<num2<<" = "<<subtract(num1,num2)<<endl;
                    break;
                case 3:
                    cout<<"\n the multiplication 0f:" <<num1<<" * "<<num2<<" = "<<multiply(num1,num2)<<endl;
                    break;
                case 4:
                    cout<<"\n the division 0f:" <<num1<<" / "<<num2<<" = "<<divide(num1,num2)<<endl;
                    break;
            }
            
            string next_calculation;
            cout<<"\nDo you want to perform another calculation? (y/n): ";
            cin>>next_calculation;
            if (next_calculation!="y") 
			{
                break;
            }
        } 
		else 
		{
            cout<<"Invalid input. Please enter a choice from 1, 2, 3, or 4."<< endl;
        }
    }
}

int main() 
{
    calculator();
    return 0;
}

