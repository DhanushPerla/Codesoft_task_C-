#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber=rand()%100+1;
    int guess=0;
    cout<<"Guess the number between 1 and 100:"<<endl;
    while (guess != randomNumber) {
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Correct! The number was " << randomNumber << "." << endl;
        }
    }
    return 0;
}
