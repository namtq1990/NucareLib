/*
 * log.h
 *
 *  Created on: Nov 15, 2021
 *      Author: quangnam
 */

#ifndef INCLUDE_COMMON_COMMON_H_
#define INCLUDE_COMMON_COMMON_H_

#include <string>
#include <stdexcept>
#include <memory>

namespace nucare {

namespace util {
std::string currentThread();
std::string currentTime();

template<typename ... Args>
inline std::string format(const std::string& format, Args ... args) {
    int size_s = std::snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
    if( size_s <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
    auto size = static_cast<size_t>( size_s );
    auto buf = std::make_unique<char[]>( size );
    std::snprintf( buf.get(), size, format.c_str(), args ... );
    return std::string( buf.get(), buf.get() + size - 1 ); // We don't want the '\0' inside
}
}

namespace log {

static const std::string TAG = "Nc";

namespace detail {
void d(const std::string& tag, const std::string& message);
void e(const std::string& tag, const std::string& message);
}

inline void d_tag(const std::string& tag, const std::string& message) { detail::d(tag, message); }

inline void e_tag(const std::string& tag, const std::string& message) { detail::e(tag, message); }

template<typename ... Args>
inline void d_tag(const std::string& tag, const std::string& _format, Args ... args) { detail::d(tag, util::format(_format, args...)); }

template<typename ... Args>
void e_tag(const std::string& tag, const std::string& _format, Args ... args) { detail::e(tag, util::format(_format, args...)); }


inline void d(const std::string& message = "") { detail::d(TAG, message); }

inline void e(const std::string& message = "") { detail::e(TAG, message); }
}


}



#endif /* INCLUDE_COMMON_COMMON_H_ */
