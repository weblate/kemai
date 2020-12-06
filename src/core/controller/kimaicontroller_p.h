#pragma once

#include "kimaicontroller.h"

#include "client/kimaiclient.h"

namespace kemai::controller {

class KimaiController::KimaiControllerPrivate
{
public:
    KimaiControllerPrivate();

    void refreshClient();

public:
    client::KimaiClient mClient;
    ActivityController mActivityController;
    CustomerController mCustomerController;
    ProjectController mProjectController;
    TagController mTagController;
};

} // namespace kemai::controller
