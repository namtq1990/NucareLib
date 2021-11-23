/*
 * spectrum.h
 *
 *  Created on: Nov 15, 2021
 *      Author: quangnam
 */

#ifndef INCLUDE_MODEL_SPECTRUM_H_
#define INCLUDE_MODEL_SPECTRUM_H_

#include <array>
#include <ctime>

namespace nucare {
static const int CHSIZE = 1024;
}

class Spectrum {
private:
    std::array<double, nucare::CHSIZE> mSPC;
    double mAcqTime = 0;
    std::time_t mDate;
public:
    void setData(std::array<double, nucare::CHSIZE>& data);
    void setData(double* data, int length);
    void setDate(const time_t time);
    std::array<double, nucare::CHSIZE>& data();
    std::time_t getDate();

};



#endif /* INCLUDE_MODEL_SPECTRUM_H_ */
