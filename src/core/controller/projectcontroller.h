#pragma once

#include "controller/basecontroller.h"

namespace kemai::controller {

class ProjectController : public QObject, public BaseController
{
    Q_OBJECT
    Q_PROPERTY(kemai::client::Projects projects READ projects NOTIFY projectsChanged)

public:
    ProjectController(client::KimaiClient& kimaiClient);

    void update() override;

    void addProject(const client::Project& project);

    const client::Projects& projects() const;
    client::Projects projects(int customerId) const;

signals:
    void projectsChanged(const client::Projects& projects);

protected:
    void processReply(const client::KimaiReply& reply) override;

private:
    client::Projects mProjects;
};

} // namespace kemai::controller
