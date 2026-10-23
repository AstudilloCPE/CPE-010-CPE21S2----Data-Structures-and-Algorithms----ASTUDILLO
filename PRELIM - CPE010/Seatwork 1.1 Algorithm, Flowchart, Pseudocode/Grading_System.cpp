// Astudillo, Thomas Joseph T.
// CPE21S2

#include <iostream>
using namespace std;

int main() {
    int score1, score2, score3, sum;
    float avg;

    cout << "Please Enter Quiz 1 Score: " << endl;
    cin >> score1;
    cout << "Please Enter Quiz 2 Score: " << endl;
    cin >> score2;
    cout << "Please Enter Quiz 3 Score: " << endl;
    cin >> score3;

    sum = score1 + score2+ score3;
    avg = sum/3.0;


    cout << "The Total for all Quizzes is: " << sum << endl;
    cout << "The Average Grade for all Quizzes is: " << avg << endl;
    
    return 0;
}