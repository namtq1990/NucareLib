/*
 * spectrum.cpp
 *
 *  Created on: Nov 15, 2021
 *      Author: quangnam
 */

#include "Model/Spectrum.h"
#include <cstring>

using namespace std;

void Spectrum::setData(std::array<double, nucare::CHSIZE>& data) {
    setData(data.data(), data.size());
}

void Spectrum::setData(double* data, int length) {
//	std::copy(data, length, mSPC.data());
    memcpy(mSPC.data(), data, length);
}

void Spectrum::setDate(const time_t time) {
    mDate = time;
}

std::array<double, nucare::CHSIZE>& Spectrum::data() {
    return mSPC;
}

std::time_t Spectrum::getDate() {
    return mDate;
}

