/*
 * StackSort.h
 *
 *  Created on: 2019Äê2ÔÂ23ÈÕ
 *      Author: JUNK_CHUAN
 */

#ifndef STACKSORT_H_
#define STACKSORT_H_

#include "AStack.h"

void StackSort(AStack<int> &IN) {
	AStack<int> Temp1, Temp2;

	while (IN.length())        // Transfer to another stack.
		Temp1.push(IN.pop());
	IN.push(Temp1.pop());      // Put back one element.
	while (Temp1.length()) {   // Process rest of element.
		while (IN.topValue() > Temp1.topValue())
			Temp2.push(IN.pop());
		IN.push(Temp1.pop());  // Put the element into IN.
		while (Temp2.length()) // Put the rest element.
			IN.push(Temp2.pop());
	}
}


#endif /* STACKSORT_H_ */
