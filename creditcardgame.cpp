#include <iostream>

using namespace std;
int getDigits(const int number);
int sumOddDigits(const string cardNumber);
int sumEvenDigits(const string cardNumber);
int main(){
    string cardNumber;
    int result;
    cout << "Enter your credit card number: " << endl;
    getline (cin, cardNumber);
    result = sumOddDigits(cardNumber) + sumEvenDigits(cardNumber);
    if (result % 10 == 0){
        cout << cardNumber << " is a valid credit card number.";
    }
    else
    {
        cout << cardNumber << " is an invalid credit card number.";    
    }
    return 0;
}
int getDigits(const int number){
    return number % 10 + (number / 10 % 10);
}
    
int sumOddDigits(const string cardNumber){
    int num;
    for (int i = (sizeof(cardNumber)/sizeof(cardNumber[0])) - 1; i > 0; i-= 2)
    {
        num += cardNumber[i] - '0';
        return num;
    }
}
int sumEvenDigits(const string cardNumber){
    int num, result;
    for (int i = (sizeof(cardNumber)/sizeof(cardNumber[0])) - 2; i >= 0; i-= 2)
    {
        num += getDigits((cardNumber[i]-'0')*2);    
    }
    return num;
}