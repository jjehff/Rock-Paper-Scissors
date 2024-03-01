#include <iostream>
#include <string>
#include <random>
#include <ctime>

bool PlayGame(int &w, int &l, int &t) {
	char answer;
	std::cout << "Would you like to play again? (Y/N) ";
	std::cin >> answer;
	if (answer != 121 && answer != 89) {
		std::cout << "Thanks for playing!\n";
		printf("You won %d round(s), tied %d round(s), and lost %d round(s)!\n", w, l, t);
		return false;
	}
	else {
		return true;
	}
}

int choice() {
	std::string answer;
	char realAnswer;
	while (true) {
		std::cout << "Rock Paper or Scissors?\n";
		std::cin >> answer;
		for (int i = 0; i < answer.size(); i++) {
			if (isupper(answer[i]) == true) {
				answer[i] = answer[i] + 32;
			}
		}
		if (answer == "rock") {
			realAnswer = 1;
			return realAnswer;
		}
		else if (answer == "paper") {
			realAnswer = 2;
			return realAnswer;
		}
		else if (answer == "scissors") {
			realAnswer = 3;
			return realAnswer;
		}
		else {
			std::cout << "Invalid answer! Try again!\n";
		}
	}
}

int RandomChoice() {
	int choice = (rand() % 3) + 1;
	return choice;
}

void whoWins(int c1, int c2, int &w, int &l, int &t) {
	if (c1 == 1) { // YOU PICKED ROCK
		if (c2 == 1) {
			std::cout << "You tied! Your opponent picked Rock!\n";
			t++;
		}
		else if (c2 == 2) {
			std::cout << "You lose! Your opponent picked Paper!\n";
			l++;
		}
		else {
			std::cout << "You win! Your opponent picked Scissors!\n";
			w++;
		}
	}
	else if (c1 == 2) { // YOU PICKED PAPER
		if (c2 == 1) {
			std::cout << "You win! Your opponent picked Rock!\n";
			w++;
		}
		else if (c2 == 2) {
			std::cout << "You tied! Your opponent picked Paper!\n";
			t++;
		}
		else {
			std::cout << "You lose! Your opponent picked Scissors!\n";
			l++;
		}
	}
	else { // YOU PICKED SCISSORS
		if (c2 == 1) {
			std::cout << "You lose! Your opponent picked Rock!\n";
			l++;
		}
		else if (c2 == 2) {
			std::cout << "You win! Your opponent picked Paper!\n";
			w++;
		}
		else {
			std::cout << "You tied! Your opponent picked Scissors!\n";
			t++;
		}
	}
}

int main() {
	int win = 0, lose = 0, tie = 0;
	srand(NULL);
	char answer;
	std::cout << "Welcome to Rock Paper Scissors!\nWould you like to play a game? (Y/N) ";
	std::cin >> answer;
	if (tolower(answer) != 'y') {
		std::cout << "Goodbye!\n";
	}
	else {
		while (true) {
			int choice1 = choice();
			int choice2 = RandomChoice();
			whoWins(choice1, choice2, win, lose, tie);
			if (PlayGame(win, lose, tie) == false) {
				break;
			}

		}
	}

}
