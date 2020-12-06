#include "customercontroller.h"

#include "client/kimairequestfactory.h"

using namespace kemai::client;
using namespace kemai::controller;

CustomerController::CustomerController(client::KimaiClient& kimaiClient) : BaseController(kimaiClient)
{
    addHandledMethod(client::ApiMethod::Customers);
}

void CustomerController::update()
{
    kimaiClient().sendRequest(KimaiRequestFactory::customers());
}

void CustomerController::addCustomer(const Customer& customer)
{
    kimaiClient().sendRequest(KimaiRequestFactory::customerAdd(customer));
}

const Customers& CustomerController::customers() const
{
    return mCustomers;
}

void CustomerController::processReply(const KimaiReply& reply)
{
    mCustomers = reply.get<Customers>();
    emit customersChanged(mCustomers);
}
