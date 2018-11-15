/*
Author: 		Annie Wu
Assignment:		Homework #3

Class:			CS 2560.01 - C++ Programming
Date:			16 November 2018

Purpose:		This file contains the Question class.

*/

#pragma once
#include <string>
#include <vector>
using namespace std;

class Question {

private:
	int correctAnswer;
	string theQuestion;
	string answer1;
	string answer2;
	string answer3;
	string answer4;

public:

	int getAnswer();
	void printQuestion();
	string getQuestion();
	Question(string ques, string a1, string a2, string a3, string a4, int correctAnswer);

};

