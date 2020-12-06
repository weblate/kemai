#pragma once

#include "controller/basecontroller.h"

namespace kemai::controller {

class ActivityController : public QObject, public BaseController
{
    Q_OBJECT
    Q_PROPERTY(kemai::client::Activities activites READ activites NOTIFY activitesChanged)

public:
    ActivityController(client::KimaiClient& kimaiClient);

    void update() override;

    void addActivity(const client::Activity& activity);
    const client::Activities& activites() const;

signals:
    void activitesChanged(const client::Activities& customers);

protected:
    void processReply(const client::KimaiReply& reply) override;

private:
    client::Activities mActivites;
};

} // namespace kemai::controller
