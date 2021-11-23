/*
 * log.h
 *
 *  Created on: Nov 15, 2021
 *      Author: quangnam
 */

#ifndef INCLUDE_COMMON_COMMON_H_
#define INCLUDE_COMMON_COMMON_H_

#include <string>

namespace nucare {

namespace util {
std::string currentThread();
}

namespace log {

static const std::string TAG = "Nc";

void d_tag(const std::string& tag, const std::string& message);

//template<typename ... Args>
//inline void d_tag(const std::string& tag, const std::string& _format, Args ... args) {
//	d_tag(tag, format(_format, args...));
//}

void e_tag(const std::string& tag, const std::string& message);

//template<typename ... Args>
//void e_tag(const std::string& tag, const std::string& format, Args ... args);

inline void d(const std::string& message = "") {
    d_tag(TAG, message);
}

inline void e(const std::string& message = "") {
    e_tag(TAG, message);
}
}


}



#endif /* INCLUDE_COMMON_COMMON_H_ */
