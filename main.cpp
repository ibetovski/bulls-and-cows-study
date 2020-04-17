#include <ctime>
#include <iostream>
#include <string>

#define DEBUG

using namespace std;

bool doesNumberExist(int num, int stack[], int currentIndex);
void getCowsAndBulls(int computerNumber[], int userNumber[], int& cows, int& bulls);
void getUserNumber(int userNumber[]);
void pickRandomNumber(int computerNumber[]);

int main()
{
    srand(time(NULL));

    int cows{0};
    int bulls{0};

    #ifdef DEBUG
    std::cout << "DEBUG: Verbose mode is enabled." << '\n';
    #endif

    int computerNumber[4];
    pickRandomNumber(computerNumber);

    #ifdef DEBUG
    std::cout << "Computer's number is: ";
    for (int i = 0; i < 4; i++) {
        std::cout << computerNumber[i];
    }
    std::cout << '\n';
    #endif

    do {
        int userNumber[4];
        getUserNumber(userNumber);

        getCowsAndBulls(computerNumber, userNumber, cows, bulls);

        std::cout << "Cows: " << cows << '\n';
        std::cout << "Bulls: " << bulls << '\n';
    } while (bulls < 4);

    cout << "Congratulations! You guessed!" << '\n';

    return 0;
}

bool doesNumberExist(int num, int stack[], int currentIndex) {
    bool isFound = false;
    for (int i = 0; i < 4; i++) {
        // the current index check is needed because the empty string items are 0
        // so when we want to inser 0, it says "it exists already".
        // But if we want to insert 0 in position 2 and there is 0 there,
        // it means it is empty so we can insert.
        if (stack[i] == num && currentIndex != i) {
            isFound = true;
            return isFound;
        }
    }
    return isFound;
}

void pickRandomNumber(int computerNumber[]) {
    for (int i = 0; i < 4; i++) {
        int randNumber;
        if (i == 0) {
            do {
                randNumber = rand() % 10;
                #ifdef DEBUG
                std::cout << "Computer picked random number for index (" << i << "): " << randNumber << '\n';
                #endif
            } while (randNumber == 0);
        } else {
            do {
                    randNumber = rand() % 10;
                    #ifdef DEBUG
                    std::cout << "Computer picked random number for index (" << i << "): " << randNumber << '\n';
                    #endif
            } while (doesNumberExist(randNumber, computerNumber, i) == true);
        }

        computerNumber[i] = randNumber;
    }
}

void getUserNumber(int userNumber[]) {
    std::cout << "Please enter a 4 digit number and press ENTER: ";
    char input[4];

    for (int i = 0; i < 4; i++) {
        std::cin >> input[i];
    }

    for (int i = 0; i < 4; i++) {
        userNumber[i] = input[i] - '0';
    }

}


void getCowsAndBulls(int computerNumber[], int userNumber[], int& cows, int& bulls) {

    cows = 0;
    bulls = 0;

    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            if (computerNumber[k] == userNumber[i] && i == k) {
                bulls++;
            } else if (computerNumber[k] == userNumber[i] && i != k) {
                cows++;
            }
        }
    }
}
