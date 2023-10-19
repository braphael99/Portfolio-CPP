#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//my widdle addition function :)
int addition(int x, int y){

    int sum = x + y;

    return sum;

}

int main(){
    //intializing variables
    string name;
    int numOne;
    int numTwo;
    int guess = 0;
    
    //Providing a seed value
	srand(time(NULL));
    int randomNum = rand() % 1000 + 1;

    //asking some test questions
    cout << "What is your name? \n";
    cin >> name;
    cout << "Your name is " << name << "\n";
    
    cout << "Now we will add two numbers. \n What is your first number? \n";
    cin >> numOne;
    cout << "\nNow for the second number:\n";
    cin >> numTwo;

    cout << "Your added numbers are " << addition(numOne, numTwo) << "\n";

    //guessing game!
    cout << "Okay now we will play a game where we guess a random number between 1 and 1000.\n";

    while (guess != randomNum){
        
        cout << "Your guess: \n";
        cin >> guess;

        if(guess != randomNum){
            cout << "Ohhhh so close NERD!!\n";

            if(guess > randomNum){
                cout << "Guess lower you bum\n";
            }
            else{
                cout << "Guess higher LOSERRRRR\n";
            }
        }
        else {
            cout << "You win butthole enjoy your fake internet points\n\n";

        }

        if(guess == 0){
            cout << "Wow, do you give up on everything " << name << "?? The answer was " << randomNum << "\n";
            break;
        }

    }

    return 0;
}