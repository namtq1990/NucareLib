#ifndef NCMANAGER_H
#define NCMANAGER_H

#include "Hw/HwConnector.h"
namespace nucare {

class NcManager
{
private:
    std::shared_ptr<Spectrum> mCurSpc;
    rxcpp::subscription mSpcSubscription;
    std::unique_ptr<HwConnector> mHwController;
public:
    NcManager();
    void setHwController(HwConnector* controller);
};

}

#endif // NCMANAGER_H
