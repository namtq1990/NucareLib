/*
 * common.cpp
 *
 *  Created on: Nov 15, 2021
 *      Author: quangnam
 */

#include "Common/BaseCommon.h"
#include <thread>
#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

void nucare::log::detail::d(const std::string& tag, const std::string& message) {
    auto time = nucare::util::currentTime();
    cout << '[' << time << "]: "<< message << endl;
}

void nucare::log::detail::e(const std::string& tag, const string& message) {
    auto time = nucare::util::currentTime();
    cout << '[' << time << "]: "<< message << endl;
}

std::string nucare::util::currentThread() {
    auto ss = stringstream();
    auto id = std::this_thread::get_id();
    ss << id;

    return ss.str();
}

std::string nucare::util::currentTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
