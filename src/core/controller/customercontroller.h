#pragma once

#include "controller/basecontroller.h"

namespace kemai::controller {

class CustomerController : public QObject, public BaseController
{
    Q_OBJECT
    Q_PROPERTY(kemai::client::Customers customers READ customers NOTIFY customersChanged)

public:
    CustomerController(client::KimaiClient& kimaiClient);

    void update();

    void addCustomer(const client::Customer& customer);
    const client::Customers& customers() const;

signals:
    void customersChanged(const client::Customers& customers);

protected:
    void processReply(const client::KimaiReply& reply) override;

private:
    client::Customers mCustomers;
};

} // namespace kemai::controller
