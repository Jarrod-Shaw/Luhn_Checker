// Credit Card checker using "Luhn"
#include <iostream>
#include <string>
using namespace std;

long cardNum;
long i=15;
int dSum = 0;
int d1, d2, d3, d4, d5, d6, d7;

//int loop = 7; //loop counter for check digits
int arPos = 14; //array position for selecting the digit to check
//BOTH of these are decremented in the function checkDigit()

long cn_array[16];
int overNine[2];

void makeArray(long c)
{
    while(c)
    {
        cn_array[i] = c % 10;
        //cout<<cn_array[i];
        c /= 10;
        i--;
    }
    //for(long n = 0; n<=15; n++) //n-1 because array is base 0
    //  cout<<cn_array[n];
}

int addDoubleDigits(int num)
{
    int n=0;
    while(num)
    {
        overNine[n] = num %10;
        num /= 10;
        n++;
    }
    return overNine[0]+overNine[1];
}

int checkOverNine(int in)
{
    if(in>9)
    {
        addDoubleDigits(in);
    }
    else
    {
        return in;
    }
}

int checkDigit(int dgt)
{
    dgt = cn_array[arPos] * 2;
    dgt = checkOverNine(dgt);
    cn_array[arPos] = dgt;
    arPos -=2;
    
    return dgt;
}

int main()
{
    cout<<"What is the card number? \n(16 digits, no dashes)\n\n-->";
    cin>>cardNum;
    makeArray(cardNum);
    
    d1 = checkDigit(cn_array[arPos]);
    d2 = checkDigit(cn_array[arPos]);
    d3 = checkDigit(cn_array[arPos]);
    d4 = checkDigit(cn_array[arPos]);
    d5 = checkDigit(cn_array[arPos]);
    d6 = checkDigit(cn_array[arPos]);
    d7 = checkDigit(cn_array[arPos]);
    
    cout<<"\n....adding up all the digits\n"<<endl;
    
    for(int j = 0; j<15; j++)
    {
        dSum += cn_array[j];
    }
        //cout<<dSum<<endl;       ///moar testing... user.drinkCoffee()
    
    cout<<"\nCHECKING VALIDITY!!"<<endl;
    if(dSum % 10 == 0)
    {
        cout<<"\nCONGRATULATIONS!!!\n\nIt's a valid Number!"<<endl;
        return 0;
    }
    else
    {
        cout<<"Sorry!\n\nBetter check again!"<<endl;
        return 1;
    }
    
}
