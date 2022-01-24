#include "NcManager.h"
#include "Signal.h"
#include "Common/BaseCommon.h"
using namespace std;

nucare::NcManager::NcManager() : mHwController()
{

}

void nucare::NcManager::setHwController(HwConnector *controller) {
    if (mHwController == nullptr) {
        mHwController = std::unique_ptr<HwConnector>(controller);
    } else {
        mHwController.reset(controller);
    }
    mSpcSubscription.unsubscribe();
    mSpcSubscription = controller->getSpectrumSubjects().get_observable().subscribe([&](shared_ptr<Spectrum> spc) {
            mCurSpc = spc;
    });
}
