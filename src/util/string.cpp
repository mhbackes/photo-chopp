/*
 * String.cpp
 *
 *  Created on: 07/09/2015
 *      Author: mhbackes
 */

#include "string.h"

namespace util {

std::string String::getExtension(const std::string s) {
	return s.substr(s.find_last_of(".") + 1);
}

} /* namespace util */
