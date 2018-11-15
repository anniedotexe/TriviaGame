/*
Author: 		Annie Wu
Assignment:		Homework #3

Class:			CS 2560.01 - C++ Programming
Date:			16 November 2018

Purpose:		This file contains the Player class.

*/

#pragma once
#include "Question.h"
using namespace std;

class Player {

private:
	vector<Question *> right;
	vector<Question *> wrong;

public:
	void addRight(Question *q);
	void addWrong(Question *q);
	void printIfRight(Question *q);
	void resetRightWrong();
};
