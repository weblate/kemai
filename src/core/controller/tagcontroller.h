#pragma once

#include "controller/basecontroller.h"

namespace kemai::controller {

class TagController : public QObject, public BaseController
{
    Q_OBJECT
    Q_PROPERTY(kemai::client::Tags tags READ tags NOTIFY tagsChanged)

public:
    TagController(client::KimaiClient& kimaiClient);

    void update() override;

    const client::Tags& tags() const;

signals:
    void tagsChanged(const client::Tags& tags);

protected:
    void processReply(const client::KimaiReply& reply) override;

private:
    client::Tags mTags;
};

} // namespace kemai::controller
