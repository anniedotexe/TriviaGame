/*
Author: 		Annie Wu
Assignment:		Homework #3

Class:			CS 2560.01 - C++ Programming
Date:			16 November 2018

Purpose:		This file contains the number of players and which questions each player answered right/wrong.

*/

#include "Player.h"
#include "Question.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//add question to right vector
void Player::addRight(Question* q) {
	right.push_back(q);
}

//add question to wrong vector
void Player::addWrong(Question* q) {
	wrong.push_back(q);
}

//print question if answered right
void Player::print(Question* q) {

	int sizeRight = static_cast<int>(right.size());
	int sizeWrong = static_cast<int>(wrong.size());

	//if the right vector is empty, the question must be in the wrong vector
	if (right.empty()) {
		for (int i = 0; i < sizeWrong; i++) {
			//if the question is in the right vector, print the question
			if (wrong[i] == q) {
				cout << "     " << left << setw(60) << q->getQuestion() << setw(10) << " WRONG" << endl;
			}
		}
	}

	//if  the wrong vector is empty, the question must be in the right vector
	else if (wrong.empty()) {
		for (int i = 0; i < sizeRight; i++) {
			//if the question is in the right vector, print the question
			if (right[i] == q) {
				cout << "     " << left << setw(60) << q->getQuestion() << setw(10) << " RIGHT" << endl;
			}
		}
	}

	//neither are empty, so just check both vectors for the question
	else {
		//look through right vector to see if question q is in it
		for (int i = 0; i < sizeRight; i++) {
			//if the question is in the right vector, print the question
			if (right[i] == q) {
				cout << "     " << left << setw(60) << q->getQuestion() << setw(10) << " RIGHT" << endl;
				return;
			}
		}
		//look through wrong vector to see if question q is in it
		for (int i = 0; i < sizeWrong; i++) {
			//if the question is in the right vector, print the question
			if (wrong[i] == q) {
				cout << "     " << left << setw(60) << q->getQuestion() << setw(10) << " WRONG" << endl;
				return;
			}
		}
	}
}

//reset right and wrong vectors
void Player::resetRightWrong() {
	right.clear();
	wrong.clear();
}
