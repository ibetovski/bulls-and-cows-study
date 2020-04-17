#include <ctime>
#include <iostream>
#include <string>

using namespace std;

bool isNumberExist(int num, int stack[], int currentIndex);


void pickRandomNumber(int computerNumber[]) {
//    int computerNumber[4];
//    srand(time(NULL));

    for (int i = 0; i < 4; i++) {
        int randNumber;
        if (i == 0) {
            do {
                randNumber = rand() % 10;
                std::cout << "Computer picked random number for index (" << i << "): " << randNumber << '\n';
            } while (randNumber == 0);
        } else {
            do {
                    randNumber = rand() % 10;
                    std::cout << "Computer picked random number for index (" << i << "): " << randNumber << '\n';
            } while (isNumberExist(randNumber, computerNumber, i) == true);
        }

        computerNumber[i] = randNumber;
    }

//    return computerNumber;
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

void blah(int arr[]) {
    arr[0] = 2;
    arr[1] = 3;
}

int main()
{
    srand(time(NULL));

    int cows{0};
    int bulls{0};

//    int computerNumber[4];
    int computerNumber[4];
    pickRandomNumber(computerNumber);

    do {
        int userNumber[4];
        getUserNumber(userNumber);

        getCowsAndBulls(computerNumber, userNumber, cows, bulls);


        std::cout << "Cows: " << cows << '\n';
        std::cout << "Bulls: " << bulls << '\n';
    } while (bulls < 4);

    cout << "Congratulations! You guessed!" << '\n';

//    return 0;




//    std::cout << rand() % 10 << '\n';
//    std::cout << "Enter a number: ";
//    // To get the input in an array one by split by  char, we should use char input
//    // Later we should convert all of them to int (by usin "number - '0'" which strips the ASCI char
//    char input[4];
//
//    for (int i = 0; i < 4; i++) {
//        std::cin >> input[i];
//    }
//
//    int userInputInt[4];
//
//    for (int i = 0; i < 4; i++) {
//        userInputInt[i] = input[i] - '0';
//    }
//
//    cout << '\n';

    // convert the input to numbers.
//    int userGuessInt[4];
//
//    for (int i = 0; i < 4; i++) {
//        std::cout << input[i] << '\n';
//    }

//    std::cout << userGuessInt[0] << '\n';

    return 0;
}

bool isNumberExist(int num, int stack[], int currentIndex) {
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

