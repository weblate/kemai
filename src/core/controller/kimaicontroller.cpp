#include "kimaicontroller.h"
#include "kimaicontroller_p.h"

#include "settings.h"

using namespace kemai::core;
using namespace kemai::controller;

/*
 * Private impl
 */
KimaiController::KimaiControllerPrivate::KimaiControllerPrivate()
    : mActivityController(mClient), mCustomerController(mClient), mProjectController(mClient), mTagController(mClient)
{}

void KimaiController::KimaiControllerPrivate::refreshClient()
{
    const auto& settings = Settings::load();
    mClient.setHost(settings.kimai.host);
    mClient.setUsername(settings.kimai.username);
    mClient.setToken(settings.kimai.token);

    for (auto bc :
         QVector<BaseController*>{&mActivityController, &mCustomerController, &mProjectController, &mTagController})
    {
        bc->update();
    }
}

/*
 * Public impl
 */
KimaiController::KimaiController() : mD(new KimaiControllerPrivate) {}

KimaiController::~KimaiController() {}

void KimaiController::refreshClient()
{
    mD->refreshClient();
}

ActivityController& KimaiController::activityController() const
{
    return mD->mActivityController;
}

CustomerController& KimaiController::customerController() const
{
    return mD->mCustomerController;
}

ProjectController& KimaiController::projectController() const
{
    return mD->mProjectController;
}

TagController& KimaiController::tagController() const
{
    return mD->mTagController;
}
