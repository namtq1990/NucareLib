QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Common/BaseCommon.cpp \
    Model/Event.cpp \
    Model/Isotopes.cpp \
    Model/Spectrum.cpp \
    Nucare/NcManager.cpp

HEADERS += \
    Common/BaseCommon.h \
    Model/Event.h \
    Model/Isotopes.h \
    Model/Spectrum.h \
    Nucare/Hw/HwConnector.h \
    Nucare/NcManager.h \
    Nucare/Signal.h

DEFINES += MAKE_TEST_LIB

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

