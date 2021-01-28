# Wheel of Fortune
Wheel of Fortune is a popular game, mainly known from the popular Wheel of Fortune Game Show.
### Content

* How the Game works
* The Rules of the Game
* Terminal input & Handling
* Special “Cases”
* Explanation Main.c
* Explanation Game.c

### How the Game works
There are 3 Puzzles (Words, sentences) and 3 Rounds. At each Round one of the Puzzles will be hidden and the players need to guess consonants or buy vowels to reveal the Puzzle so guessing the entire Puzzle becomes easier. Before they are able to guess, they spin the wheel which can land on:
• Land on Lose Turn -> Lose Turn and next Player continues
• Land on Extra Turn -> Spin Again
• Land on Bankrupt -> Lose Turn and lose all Money from the Current Round
• Land on Money -> Able to now guess a consonant/or a Vowel -> Get Money TIMES the occurrences of the guessed consonant/vowel.
If a guess has been correct, the player will then be allowed to Guess the entire Puzzle. If he decides to do so, he has to enter the Puzzle (lower/upper-case does not matter). If he guesses correctly, the round ends and he is allowed to keep all the money he has earned in the Round, while the other players will end the Turn with 0.
If he decides to not guess the Puzzle, the wheel will be spun again.
A Round ends when the Puzzle has been GUESSED (Enter entire Puzzle) by a player.
If 3 Rounds have been played, the Game ends.
### The Rules of the Game
You can not buy a vowel on your first turn in a Round.
You can not enter a vowel in the first turn in a Round.
If you land on a wedge containing money value, a correct guess of a letter will grant you the Occurrence of that Letter in the Puzzle * The Money value you landed on.
You can only guess the Puzzle if you are asked if you want to guess the Puzzle.
You don’t have to guess the “whitespaces” inbetween Words in the Puzzle.
After each round the money wedge with the highest value will be increased by 500.

### Terminal Input & Handling
* As soon as you launch the WOF Game, you will be asked to enter the first 3 Puzzles. Note that we have decided that a Puzzle can’t be longer than 50 characters! You need to enter the sentences 1 by 1 and confirming each time with ENTER. Your entries will be trimmed of leading and trailing whitespaces.
* Now you will be asked to enter the amount of players. The game has been designed to be played by 2 or 3 players. Any INTEGER confirmed by Enter that is not 2 or 3, will be ignored and you will be prompted for the amount again. Any decimal number (e.g. 3,9) will be accepted if the number before the decimal point contains ONLY 2 or 3.
Any character (unless 2 or 3) will be ignored and prompt you to enter the amount again.
Any string (e.g. ab!, de/.f) will be ignored unless it leads with 2 or 3 (e.g. 2dfgdfter, 2/, 3f!!2h).
* Now that you have entered the amount of players, you will be asked to enter the Name of the players 1 by 1. Here aswell, we have decided to trim leading and trailing whitespaces.
Any character/string entered here is accepted. People might have weird names like “X Æ A-12”!
* Now the game can start. First we will print the Puzzle that needs to be guessed. It will be hidden by dashes ‘-‘.
Example: “The Walking Dead” will be “--- ------- ----“
* A random player will be selected, and after that they will play one after the other.
Example: 3 Players, Player 2 starts. Therefore, the order will be: (P2->P3->P1->P2->P3)
* The Wheel will be spun as soon as its a players turn. After the animation ends, the Terminal will print what you have landed on. The first 4 ‘-‘ in the Wheel are Lose Turn, Bankrupt, Bankrupt, Extra Turn. The following dashes are money values in an ascending fashion.
Based on what you land the following will happen:
    * Lose Turn: Lose your turn, going to next Player
    * Bankrupt: Lose your turn and all the Money you have gathered in the round.
    * Extra Turn: The wheel will be spun again.
    *  Money
        *   Is it the first time you are guessing in this Round?
             * Yes: You will be asked to enter a consonant. Vowels are not accepted, and if Entered, you will be prompted to enter a consonant again. Any character is accepted. Strings are also accepted, but only the first character is considered and therefore your guess.
                    * Your consonant is in the Puzzle: You get the Money you landed on * the occurrence of the consonant.
                    * Your consonant is not in the Puzzle: You don’t get anything and it’s the next players turn now.
            * No: You will be asked to enter a consonant OR buy a Vowel.
Any character is accepted. Strings are also accepted, but only the first character is considered and therefore your guess.
                    * Same rules Apply to guessing as above.
                    * You buy a vowel contained in the Puzzle: You lose 250 Dollars but get the Money you landed on * the occurrence of the Vowel.
                    * You buy a vowel NOT contained in the Puzzle: You lose 250 Dollars and it’s the next players turn now.
        * What happens after a successful guess?
             *   You will be asked if you want to guess the Puzzle.
                    * You want to guess the Puzzle: You now need to enter the entire puzzle. Upper/lower-case does not matter.
                        * You entered the wrong Puzzle: Next Player
                        * You entered the correct Puzzle: You win the round and the round ends.
                    * You don’t want to guess the Puzzle:
                        * The Wheel will be spun again for you.
        * What happens after a Round ends?
The person that correctly guessed the Puzzle finishes the Round with the Money he has gathered in that particular Round. Any other people will not have gained any Money in that Round. At the end of each Round, a Standing of the overall Game will be printed.

### Special Rules
* If you don’t have enough money to buy a vowel, but have the option to buy one, you are allowed to go into negative money amount.
* If all consonants have been guessed in the Puzzle, and now it is your first turn in the current Round, you will be allowed to buy a vowel, even though it is your first time playing in the Round.
* If the puzzle has been fully revealed and the turn goes over to you due to the previous player “guessing (pronounciating)” the puzzle in a wrong manner, the Wheel will spin but you will only be allowed to enter your guess for the entire Puzzle since there a no more letters to be revealed. If you guessed correctly, you will receive the amount of money that you landed on, if guessed wrongly, it will be the next players turn.

### Collaborators
This Project was done for the Programming 2 Project at the University of Luxembourg (IT Studies).
The other two Collaborators were Hugo Cossa and Thomas Gillet.
