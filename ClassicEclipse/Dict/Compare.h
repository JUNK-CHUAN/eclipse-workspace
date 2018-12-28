/*
 * Compare.h
 *
 *  Created on: Dec 24, 2018
 *      Author: junk_chuan
 */

#ifndef COMPARE_H_
#define COMPARE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class intintCompare { // Comparator class for integer keys
public:
	static bool lt(int x, int y) { return x < y; }
	static bool eq(int x, int y) { return x == y; }
	static bool gt(int x, int y) { return x > y; }
};


class CCCompare { // Compare two character strings
public:
  static bool lt(char* x, char* y)
    { return strcmp(x, y) < 0; }
  static bool eq(char* x, char* y)
    { return strcmp(x, y) == 0; }
  static bool gt(char* x, char* y)
    { return strcmp(x, y) > 0; }
};

#endif /* COMPARE_H_ */
