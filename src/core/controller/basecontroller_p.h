#pragma once

#include "basecontroller.h"

namespace kemai::controller {

class BaseController::BaseControllerPrivate : public QObject
{
    Q_OBJECT

public:
    BaseControllerPrivate(BaseController* c, client::KimaiClient& client);

public:
    client::KimaiClient& kimaiClient;
    QVector<client::ApiMethod> methodsHandled;

private slots:
    void onReplyReceived(const client::KimaiReply& reply);

private:
    BaseController* const mQ;
};

} // namespace kemai::controller
