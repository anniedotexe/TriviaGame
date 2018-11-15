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
#include <vector>
using namespace std;

//add question to right vector
void Player::addRight(Question *q) {
	right.push_back(q);
}

//add question to wrong vector
void Player::addWrong(Question *q) {
	wrong.push_back(q);
}

//print question if answered right
void Player::printIfRight(Question *q) {

	int size = static_cast<int>(right.size());

	//if no questions are in the right vector
	if (size == 0) {
		cout << "";
	}
	else {
		//look through right vector to see if question q is in it
		for (int i = 0; i < size; i++) {
			//if the question is in the right vector, print the question
			if (right[i] == q) {
				cout << "\t" << q->getQuestion() << endl;
			}
		}
	}
}

//reset right and wrong vectors
void Player::resetRightWrong() {
	right.clear();
	wrong.clear();
}
