/*
 * String.h
 *
 *  Created on: 07/09/2015
 *      Author: mhbackes
 */

#ifndef STRING_H_
#define STRING_H_

#include <string>

namespace util {

class String {
public:
	virtual ~String();

	static std::string getExtension(const std::string s);
};

} /* namespace util */

#endif /* STRING_H_ */
