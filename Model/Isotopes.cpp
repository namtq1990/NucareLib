#include "Isotopes.h"
#include <stdexcept>
using namespace std;

const string* CLASS_NAME = new string[UNKNOWN + 1] {
        "IND",
        "UNKNOWN"
        };

const uint* CLASS_COLOR = new uint[UNKNOWN + 1] {
        0x142889,
        0xD21F25
        };

Class nucare::classFromName(const string& name) {
    for (int i = 0; i <= UNKNOWN; i++) {
        if (name == CLASS_NAME[i]) {
            return Class(i);
        }
    }

    throw std::invalid_argument("Name isn't a type of Isotope Class");
}

const string& nucare::getClassName(const Class& clazz) {
    return CLASS_NAME[clazz];
}

uint nucare::getColorForClass(const Class& clazz) {
    return CLASS_COLOR[clazz];
}

Isotopes::Isotopes(const Class& clazz, const std::string name) : mClass(clazz),
    mName(name) {

}
