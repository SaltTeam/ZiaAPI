/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 11/12/2017
 * @package Zia
 */

#include <memory>
#include "ModExample.hpp"

extern "C"
{
ModExample* zia_create_module(void)
{
    return new ModExample;
}
}

bool ModExample::initialize()
{
    // Init your resources if needed
    return true;
}

void ModExample::shutdown()
{
    // Clean and release your resources
}

inline int ModExample::getPostRequestWeight() const
{
    // You can return a static value
    // Or return a value you get from the settings

    // Not doing error check, this is just an example
    auto weight = this->_settings.find("ExamplePostRequestWeight");
    if (weight != this->_settings.end())
	return std::atoi(weight->second.c_str());
    return 42;
}

Zia::ResponsePtr ModExample::catchPostRequest(Zia::Session &session, Zia::Request& request)
{
    Zia::ResponsePtr response = std::make_unique<Zia::Response>();

    response->getContent().set(
	"<h1>Hello World!</h1><h3>You are connecting from " + session.getIpv4() + "</h3><p>This body was generated by ModExample</p>"
    );
    response->getStatus().setStandardStatus(Zia::Status::OK);
    response->getHeaders().addHeader(
	Zia::Header(
	    Zia::Header::ResponseHeader::SET_COOKIE,
	    "ModExample=Cookie42; Path=/"
	)
    );
    return response;
}

inline int ModExample::getPostResponseWeight() const
{
    // You can return a static value
    // Or return a value you get from the settings

    // Not doing error check, this is just an example
    auto weight = this->_settings.find("ExamplePostResponseWeight");
    if (weight != this->_settings.end())
	return std::atoi(weight->second.c_str());
    return 42;
}

void ModExample::catchPostResponse(Zia::Session &session, std::string& response)
{
    // You can do some shit with the raw data here
    // Maybe a good place for your ModSSL implementation ;)
}

inline int ModExample::getPreRequestWeight() const
{
    // You can return a static value
    // Or return a value you get from the settings

    // Not doing error check, this is just an example
    auto weight = this->_settings.find("ExamplePreRequestWeight");
    if (weight != this->_settings.end())
	return std::atoi(weight->second.c_str());
    return 42;
}

void ModExample::catchPreRequest(Zia::Session &session, std::string& request)
{
    // You can do some shit with the raw data here
    // Maybe a good place for your ModSSL implementation ;)
}

inline int ModExample::getPreResponseWeight() const
{
    // You can return a static value
    // Or return a value you get from the settings

    // Not doing error check, this is just an example
    auto weight = this->_settings.find("ExamplePreResponseWeight");
    if (weight != this->_settings.end())
	return std::atoi(weight->second.c_str());
    return 42;
}

void ModExample::catchPreResponse(Zia::Session &session,
				  const Zia::ConstRequest& request,
				  Zia::Response& response)
{
    response.getHeaders().addHeader(
	Zia::Header(
	    Zia::Header::ResponseHeader::SERVER, "Zia"
	)
    );
}
