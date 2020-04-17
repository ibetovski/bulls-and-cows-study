# Bulls and Cows study with C++

This repository contains my attempt of doing Bulls and Cows game with C++. It is a study so everything here is done while I am trying to learn coding with C++.

Here is how it looks like in normal mode:

![Normal mode](https://raw.githubusercontent.com/ibetovski/bulls-and-cows-study/master/img/normal-mode.png)

And here is how it looks like in verbose mode:

![Verbose mode](https://raw.githubusercontent.com/ibetovski/bulls-and-cows-study/master/img/verbose-mode.png)

## What is done:

- The computer generates a 4 digit number
- The generated number doesn't start with 0
- The generated number consists of unique digits.
- The computer calculates the number of bulls and cows.
- The player can guess computer's number

## To do:

- Reading about Bulls and Cows algorithm
- Implementing computer guessing the player's number.
- Probably adding class to manage the logic.
- Too optimistic: UI using Qt. Should read about Qt.

## Challenges I faced so far.

This section is organized by date so there are versions through the development process.

### 2020-04-17:

- I am not sure if keeping the 4 digits in `int [4]` is as good idea as I think. The time will show
- Generating random number. `rand()` actually generates semi-random number using a seed. It took me a while to find "a solution" to generate random numbers every time.
- Generating random number. I tried to return the generated number but it didn't work because the variable pointer gets destroyed with the life of the function. So I had to populate an existing array instead.
- Getting user input as 1 character converted to int
- Calculating the number of bulls and cows and returning the result. Instead of having two separate functions and iterating the numbers more than once (currently exponentially) in order to be able to returnthe result, I decided to pass the both variables from outside as references. No idea how good it is to return something like structure instead.
- Currently I have no idea how to "teach" the computer to guess numbers.
- I still feel pretty uncomfortable with `std::cout` and `std::cin` in terms of displaying and populating an entire array.
- The pointers seems to be pretty clear untill you start using them...

