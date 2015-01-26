/*
 * Case.h
 *
 *  Created on: 20 janv. 2015
 *      Author: Guillaume
 */

#ifndef CASE_H_
#define CASE_H_

#include <iostream>

using namespace std;

class Case {
private:

public:
	Case() {
	}
	virtual ~Case();

	friend ostream& operator<<(ostream &strm, const Case &a) {
		return strm << "Case" << endl;
	}
};



#endif /* CASE_H_ */
