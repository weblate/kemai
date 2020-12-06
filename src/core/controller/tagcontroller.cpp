#include "tagcontroller.h"

#include "client/kimairequestfactory.h"

using namespace kemai::client;
using namespace kemai::controller;

TagController::TagController(client::KimaiClient& kimaiClient) : BaseController(kimaiClient)
{
    addHandledMethod(client::ApiMethod::Tags);
}

void TagController::update()
{
    kimaiClient().sendRequest(KimaiRequestFactory::tags());
}

const Tags& TagController::tags() const
{
    return mTags;
}

void TagController::processReply(const KimaiReply& reply)
{
    mTags = reply.get<Tags>();
    emit tagsChanged(mTags);
}
