#include<bits/stdc++.h>
using namespace std;
class FRACTION {
    private:
        int numerator;
        int denomenator;
    public:

        FRACTION(){
            numerator = 0;
            denomenator = 0;
        }

        int gcd(int i, int j){
            if(j%i==0)
            return i;
            else
            return gcd(j%i,i);
        }

        void getFraction(){
            cout<<"Enter the Numerator:";
            cin>>numerator;
            cout<<"Enter the denomenator:";
            cin>>denomenator;
        }

        void showFraction(){
            cout<<numerator<<"/"<<denomenator<<endl;
        }

        FRACTION addFraction(FRACTION f1, FRACTION f2){         //call by value
            FRACTION add;
            int lcm,sum = 0;

            //here lcm is the denomenator which is nothing but lcm of both denominator
            lcm = f1.denomenator>f2.denomenator ? (f1.denomenator*f2.denomenator)/gcd(f1.denomenator,f2.denomenator) :  (f1.denomenator*f2.denomenator)/gcd(f2.denomenator,f1.denomenator);         
            //here sum is the numerator of the fraction or the addition of both numerator with help of lcm(denomenator).
            sum = (f1.numerator*lcm/f1.denomenator) + (f2.numerator*lcm/f2.denomenator);

            //making numerator and denomenator in it's standard form
            add.numerator = sum>lcm ? sum/gcd(sum,lcm) : sum/gcd(lcm,sum);
            add.denomenator = sum>lcm ? lcm/gcd(sum,lcm) : lcm/gcd(lcm,sum);

            return add;
        }

        FRACTION subFraction(FRACTION &f1, FRACTION &f2){       //call by reference
            FRACTION sub;
            int lcm,minus = 0;

            //here lcm is the denomenator which is nothing but lcm of both denominator
            lcm = f1.denomenator>f2.denomenator ? (f1.denomenator*f2.denomenator)/gcd(f1.denomenator,f2.denomenator) :  (f1.denomenator*f2.denomenator)/gcd(f2.denomenator,f1.denomenator);         
            //here minus is the numerator of the fraction or the substraction of both numerator with help of lcm(denomenator).
            minus = (f1.numerator*lcm/f1.denomenator) - (f2.numerator*lcm/f2.denomenator);

            //making numerator and denomenator in it's standard form
            sub.numerator = minus>lcm ? minus/gcd(minus,lcm) : minus/gcd(lcm,minus);
            sub.denomenator = minus>lcm ? lcm/gcd(minus,lcm) : lcm/gcd(lcm,minus);

            return sub;
        }

        FRACTION mulFraction(FRACTION *f1, FRACTION *f2){       //call by address
            FRACTION mul;
            int num,den;
        
            //simple multiplication of fraction logic applied with call by address logic
            num = (f1->numerator) * (f2->numerator);
            den = (f1->denomenator) * (f2->denomenator);

            //making numerator and denomenator in it's standard form
            mul.numerator = num>den ? num/gcd(num,den) : num/gcd(den,num);
            mul.denomenator = num>den ? den/gcd(num,den) : den/gcd(den,num);

            return mul;
        }
};
int main(){

    FRACTION f1,f2,addf3,subf4,mulf5;

    cout<<"Enter the details of Fraction 1:\n";
    f1.getFraction();

    cout<<"Enter the details of Fraction 2:\n";
    f2.getFraction();

    addf3 = addf3.addFraction(f1,f2);       //call by value
    addf3.showFraction();
    subf4 = subf4.subFraction(f1,f2);       //call by reference
    subf4.showFraction();
    mulf5 = mulf5.mulFraction(&f1,&f2);     //call by address
    mulf5.showFraction();



}
    