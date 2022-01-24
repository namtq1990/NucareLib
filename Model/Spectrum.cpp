/*
 * spectrum.cpp
 *
 *  Created on: Nov 15, 2021
 *      Author: quangnam
 */

#include "Model/Spectrum.h"
#include <cstring>

using namespace std;

Spectrum::Spectrum() {

}

void Spectrum::setData(std::array<double, nucare::CHSIZE>& data) {
    setData(data.data(), data.size());
}

void Spectrum::setData(double* data, const int& length) {
    memcpy(mSPC.data(), data, length * sizeof(double));
}

void Spectrum::setData(std::array<double, nucare::CHSIZE> &&data) {
    mSPC = data;
}

void Spectrum::setDate(const time_t& time) {
    mDate = time;
}

std::array<double, nucare::CHSIZE>& Spectrum::data() {
    return mSPC;
}

std::time_t Spectrum::getDate() {
    return mDate;
}

