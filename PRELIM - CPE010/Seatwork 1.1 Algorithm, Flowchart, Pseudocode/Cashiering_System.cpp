// Astudillo, Thomas Joseph T.
// CPE21S2

#include <iostream>
#include <string>
using namespace std;

int main() {
    string item1, item2, item3;
    float price1, price2, price3, totalprice;
    float payment, change;

    cout << "Please Enter Item No. 1: " << endl;
    cin >> item1;
    cout << "Please enter The Price of Item No. 1: " << endl;
    cin >> price1;

    cout << "Please Enter Item No. 2: " << endl;
    cin >> item2;
    cout << "Please enter The Price of Item No. 2: " << endl;
    cin >> price2;

    cout << "Please Enter Item No. 3: " << endl;
    cin >> item3;
    cout << "Please enter The Price of Item No. 3: " << endl;
    cin >> price3;

    cout << "The items you have are: " << item1 << "," << item2 << "," << item3 << "." << endl;
    cout << "The Price for the respective items are: " << price1 << "," << price2 << "," << price3 << "." << endl;
    totalprice = price1 + price2 + price3;
    cout << "The total amount is: " << totalprice << endl;
    cout << "How much would you want to pay?: " << endl;
    cin >> payment;

    if (payment >= totalprice) {
        cout << "Payment Successful!" << endl;
        change = payment - totalprice;
        cout << "Your total change is: " << change << endl;

        cout << "Transaction Receipt" << endl;
        cout << item1 << " : " << price1 << endl;
        cout << item2 << " : " << price2 << endl;
        cout << item3 << " : " << price3 << endl;
        cout << "Thank you for shopping!";

    } else {
        cout << "Insufficient amount.";
    }

    
    return 0;
}