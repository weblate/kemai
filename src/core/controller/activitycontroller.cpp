#include "activitiecontroller.h"

#include "client/kimairequestfactory.h"

using namespace kemai::client;
using namespace kemai::controller;

ActivityController::ActivityController(client::KimaiClient& kimaiClient) : BaseController(kimaiClient)
{
    addHandledMethod(client::ApiMethod::Activities);
}

void ActivityController::update()
{
    kimaiClient().sendRequest(KimaiRequestFactory::activities());
}

void ActivityController::addActivity(const Activity& activity)
{
    kimaiClient().sendRequest(KimaiRequestFactory::activityAdd(activity));
}

const Activities& ActivityController::activites() const
{
    return mActivites;
}

void ActivityController::processReply(const KimaiReply& reply)
{
    mActivites = reply.get<Activities>();
    emit activitesChanged(mActivites);
}
