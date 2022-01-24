#ifndef HWCONNECTOR_H
#define HWCONNECTOR_H

#include <rxcpp/rx.hpp>
#include <Model/Spectrum.h>
#include "Nucare/Signal.h"

namespace nucare {

class HwConnector {
private:
    std::unique_ptr<rxcpp::subjects::subject<std::shared_ptr<Spectrum>>> mSpectrumSubject;
    std::unique_ptr<rxcpp::composite_subscription> mSubscriber;
public:
    explicit HwConnector() {
        mSubscriber = std::make_unique<rxcpp::composite_subscription>();
        mSpectrumSubject = std::make_unique<rxcpp::subjects::subject<std::shared_ptr<Spectrum>>>(*mSubscriber);
    }
    ~HwConnector() {
        mSubscriber->unsubscribe();
    }
    inline rxcpp::observable<std::shared_ptr<Spectrum>> getSpectrumObservable() {
        rxcpp::observable<std::shared_ptr<Spectrum>> obs = mSpectrumSubject->get_observable();
        return obs;
    }
    inline rxcpp::subjects::subject<std::shared_ptr<Spectrum>>& getSpectrumSubjects() {
        return *mSpectrumSubject;
    }
    virtual void onReady() = 0;
    virtual void onDisconnect() = 0;
};
}

#endif // HWCONNECTOR_H
