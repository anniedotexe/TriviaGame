/*
Author:			Annie Wu
Assignment:		Homework #3

Class:			CS 2560.01 - C++ Programming
Date:			16 November 2018

Purpose:		This file contains the questions and answers for the trivia game.

*/

#include "Question.h"
#include <iostream>
#include <string>
using namespace std;

int Question::getAnswer() {
	return correctAnswer;
}

void Question::printQuestion() {

	cout << theQuestion << endl;
	cout << "1. " << answer1 << endl;
	cout << "2. " << answer2 << endl;
	cout << "3. " << answer3 << endl;
	cout << "4. " << answer4 << endl;

}

string Question::getQuestion() {
	return theQuestion;
}

Question::Question(string ques, string a1, string a2, string a3, string a4, int correct) {
	theQuestion = ques;
	answer1 = a1;
	answer2 = a2;
	answer3 = a3;
	answer4 = a4;
	correctAnswer = correct;
}
