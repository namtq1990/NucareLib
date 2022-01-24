#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <string>
#include "Isotopes.h"

class Event
{
private:
    std::vector<std::string> mPhotos;
    std::vector<std::string> mVideos;
    std::vector<Isotopes> mIsotopes;
public:
    Event();
    inline std::vector<std::string>& photos() { return mPhotos; }
    inline std::vector<std::string>& videos() { return mVideos; }
    inline std::vector<Isotopes>& isotopes() { return mIsotopes; }
};

#endif // EVENT_H
