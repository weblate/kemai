#pragma once

#include <QObject>
#include <QVariantList>

#include "client/kimaiclient.h"

namespace kemai::controller {

class BaseController
{
public:
    BaseController(client::KimaiClient& kimaiClient);
    virtual ~BaseController();

    virtual void update() = 0;

protected:
    client::KimaiClient& kimaiClient() const;

    void addHandledMethod(client::ApiMethod apiMethod);

    virtual void processReply(const client::KimaiReply& reply) = 0;

private:
    class BaseControllerPrivate;
    QScopedPointer<BaseControllerPrivate> mD;
};

} // namespace kemai::controller
