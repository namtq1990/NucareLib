#ifndef ISOTOPES_H
#define ISOTOPES_H

#include <string>

enum Class {
    IND,
    UNKNOWN
};
extern const std::string* CLASS_NAME;

namespace nucare {
Class classFromName(const std::string& name);
const std::string& getClassName(const Class& clazz);
uint getColorForClass(const Class& clazz);
}

class Isotopes
{
private:
    Class mClass;
    std::string mName;
public:
    explicit Isotopes(const Class& clazz, const std::string name);
    inline Class& getClass() { return mClass; }
    inline void setClass(const Class& clazz) { mClass = clazz; }
    inline std::string& name() { return mName; }
    inline void setName(const std::string& name) { mName = name; }
};

#endif // ISOTOPES_H
