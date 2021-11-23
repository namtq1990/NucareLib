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

using namespace std;

void nucare::log::d_tag(const std::string& tag, const std::string& message) {
    cout << message << endl;
}

void nucare::log::e_tag(const std::string& tag, const string& message) {
    cout << message << endl;
}

std::string nucare::util::currentThread() {
    auto ss = stringstream();
    auto id = std::this_thread::get_id();
    ss << id;

    return ss.str();
}
