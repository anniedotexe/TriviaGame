/*
Author: 		Annie Wu
Assignment:		Homework #3

Class:			CS 2560.01 - C++ Programming
Date:			16 November 2018

Purpose:		This file creates a trivia game for multiple players. It creates 10 trivia questions,
			where each question has 4 choices with one correct answer.

*/

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Question.h"
using namespace std;

int main() {

	//Questions
	Question** q = new Question * [10];

	//Question 1
	q[0] = new Question("What city does Batman live in?",
		"Star City",
		"Gotham City", //answer
		"National City",
		"Metropolis",
		2);

	//Question 2
	q[1] = new Question("What is Captain America's shield made of?",
		"Tungsten",
		"Chromium",
		"Titanium",
		"Vibranium", //answer
		4);

	//Question 3
	q[2] = new Question("What is Superman's weakness?",
		"Cosmonite",
		"Samsonite",
		"Kryptonite", //answer
		"Plutonite",
		3);

	//Question 4
	q[3] = new Question("Who is nicknamed the Scarlett Speedster?",
		"The Flash", //answer
		"Speedball",
		"Stardust",
		"Kid Flash",
		1);

	//Question 5
	q[4] = new Question("Who was given a special serum to help the war effort?",
		"The Hulk",
		"Captain America", //answer
		"Spiderman",
		"Wolfman",
		2);

	//Question 6
	q[5] = new Question("Who is not one of the Fantastic Four superheroes?",
		"The Thing",
		"The Human Torch",
		"The Punisher", //answer
		"The Invisible Girl",
		3);

	//Question 7
	q[6] = new Question("How many Infinity Stones are there?",
		"Five",
		"Six", //answer
		"Seven",
		"Eight",
		2);

	//Question 8
	q[7] = new Question("Where in New York City would you find Daredevil?",
		"The Bronx",
		"Manhattan",
		"Hell's Kitchen", //answer
		"Queens",
		3);

	//Question 9
	q[8] = new Question("Which superheroes' real name is Arthur Curry?",
		"Aquaman", //answer
		"Hawkman",
		"The Flash",
		"The Falcon",
		1);

	//Question 10
	q[9] = new Question("Who is the medical doctor for the X-men?",
		"Ice Man",
		"Shadowcat",
		"Storm",
		"The Beast", //answer
		4);


	//number of players for the Player vector
	int size;

	cout << endl << "               Welcome to Annie's Superhero Trivia Game!!!        ";
	cout << endl << "-------------------------------------------------------------------------" << endl << endl;

	//get number of players
	cout << "Enter the number of players: ";
	cin >> size;

	//vector of players with user input size
	vector<Player*> p(size);
	for (int i = 0; i < size; i++) {
		p[i] = new Player();
	}

	bool run = true;
	//by q[] number, not Question #
	int questionNumber = 0;
	//user inputs a guess
	int guess = 0;

	while (run) {
		//5 trivia questions total
		for (int i = 0; i < 5; i++) {
			cout << "\nQuestion " << i + 1 << endl;
			cout << "-------------------------------------------------------------------------";
			//for each player j, answer question number i
			for (int j = 0; j < size; j++) {
				cout << "\nPlayer " << j + 1 << endl << endl;
				q[questionNumber]->printQuestion();
				cout << "Enter number for your answer: ";
				cin >> guess;
				//if answer is the correct answer
				if (q[questionNumber]->getAnswer() == guess) {
					//add to right vector
					p[j]->addRight(q[questionNumber]);
				}
				else {
					//add to wrong vector
					p[j]->addWrong(q[questionNumber]);
				}
			}
			//next question
			questionNumber++;
		}

		cout << endl << "-------------------------------------------------------------------------";

		//for each player print the question that were answered right
		for (int i = 0; i < size; i++) {
			cout << "\nPlayer " << i + 1 << " Results: " << endl;
			//if it is first 5 questions (q[0] to q[4])
			if (questionNumber < 6) {
				for (int j = 0; j < 5; j++) {
					p[i]->print(q[j]);
				}
			}
			//else it is the last 5 questions (q[5] to q[9])
			else {
				for (int j = 5; j < 10; j++) {
					p[i]->print(q[j]);
				}
			}
		}

		//Allow the user to play again, asking 5 different questions this time. 
		//Re-use the same Player objects, but make sure to clear the necessary data. 
		string choice;
		cout << "\n\nDo you want to play again? Y/N ";
		cin >> choice;
		if (choice == "N" || choice == "n") {
			run = false;
			cout << endl << "-------------------------------------------------------------------------";
			cout << endl << "  - ~ - ~ - Thanks for playing Annie's Superhero Trivia Game! - ~ - ~ -  ";
			cout << endl << "-------------------------------------------------------------------------";
		}
		else {
			//reset right and wrong vectors for each player
			for (int i = 0; i < size; i++) {
				p[i]->resetRightWrong();
			}

			//if the players want to replay the game after the 2nd time
			//OR play for any further odd number of times
			//reset questionNumber to go back to the first question q[0]
			if (questionNumber > 6) {
				questionNumber = 0;
			}
		}
	}

	cout << endl << endl;
	system("pause");
	return 0;
}

