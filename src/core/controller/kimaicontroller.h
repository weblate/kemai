#pragma once

#include "controller/activitycontroller.h"
#include "controller/customercontroller.h"
#include "controller/projectcontroller.h"
#include "controller/tagcontroller.h"

namespace kemai::controller {

class KimaiController
{
public:
    KimaiController();
    ~KimaiController();

    void refreshClient();

    ActivityController& activityController() const;
    CustomerController& customerController() const;
    ProjectController& projectController() const;
    TagController& tagController() const;

private:
    class KimaiControllerPrivate;
    QScopedPointer<KimaiControllerPrivate> mD;
};

} // namespace kemai::controller
