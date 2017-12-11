//
// Created by sylva on 11/12/2017.
//

#include "ModExample.hpp"

bool ModExample::initialize()
{
    return true;
}

void ModExample::shutdown()
{

}

int ModExample::getPostRequestWeight() const
{
    return 0;
}

Zia::ResponsePtr ModExample::catchPostRequest(Zia::Request &request)
{
    return nullptr;
}

int ModExample::getPostResponseWeight() const
{
    return 0;
}

void ModExample::catchPostResponse(std::string &response)
{

}

int ModExample::getPreRequestWeight() const
{
    return 0;
}

void ModExample::catchPreRequest(std::string &request)
{

}

int ModExample::getPreResponseWeight() const
{
    return 0;
}

void ModExample::catchPreResponse(const Zia::Request &request, Zia::Response &response)
{

}
