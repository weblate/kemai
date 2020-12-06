#include "projectcontroller.h"

#include "client/kimairequestfactory.h"

using namespace kemai::client;
using namespace kemai::controller;

ProjectController::ProjectController(client::KimaiClient& kimaiClient) : BaseController(kimaiClient)
{
    addHandledMethod(client::ApiMethod::Projects);
}

void ProjectController::update()
{
    kimaiClient().sendRequest(KimaiRequestFactory::projects());
}

void ProjectController::addProject(const Project& project)
{
    kimaiClient().sendRequest(KimaiRequestFactory::projectAdd(project));
}

const Projects& ProjectController::projects() const
{
    return mProjects;
}

Projects ProjectController::projects(int customerId) const
{
    Projects customerProjects;
    for (const auto& project : mProjects)
    {
        if (project.customer.id == customerId)
        {
            customerProjects << project;
        }
    }
    return customerProjects;
}

void ProjectController::processReply(const KimaiReply& reply)
{
    mProjects = reply.get<Projects>();
    emit projectsChanged(mProjects);
}
