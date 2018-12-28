/*
 * TOH.cpp
 *
 *  Created on: Dec 22, 2018
 *      Author: junk_chuan
 */
#include "Stack.h"
typedef int Pole;

// Operation choices: DOMOVE will move a disk
// DOTOH corresponds to a recursive call
enum TOHop { DOMOVE, DOTOH };

// An operation object
class TOHobj {
public:
	TOHop op;
	int num;
	Pole start, goal, tmp;

	// DOTOH operation constructor
	TOHobj(int n, Pole s, Pole g, Pole t) {
		op = DOTOH;
		num = n;
		start = s; goal = g; tmp = t;
	}

	// DOMOVE operation constructor
	TOHobj(Pole s, Pole g) {
		op = DOMOVE; start = s; goal = g;
	}
};


void TOH(int n, Pole start, Pole goal, Pole tmp, Stack<TOHobj*>& S) {
	S.push(new TOHobj(n, start, goal, tmp)); // Initial
	TOHobj* t;
	while ()
}
