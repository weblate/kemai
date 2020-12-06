#include "basecontroller.h"
#include "basecontroller_p.h"

using namespace kemai::client;
using namespace kemai::controller;

/*
 * Private impl
 */
BaseController::BaseControllerPrivate::BaseControllerPrivate(BaseController* c, KimaiClient& kc)
    : kimaiClient(kc), mQ(c)
{
    connect(&kc, &KimaiClient::replyReceived, this, &BaseController::BaseControllerPrivate::onReplyReceived);
}

void BaseController::BaseControllerPrivate::onReplyReceived(const client::KimaiReply& reply)
{
    if (methodsHandled.contains(reply.method()))
    {
        mQ->processReply(reply);
    }
}

/*
 * Public impl
 */
BaseController::BaseController(client::KimaiClient& kimaiClient) : mD(new BaseControllerPrivate(this, kimaiClient)) {}

BaseController::~BaseController() {}

KimaiClient& BaseController::kimaiClient() const
{
    return mD->kimaiClient;
}

void BaseController::addHandledMethod(client::ApiMethod apiMethod)
{
    mD->methodsHandled.append(apiMethod);
}
