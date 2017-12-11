#include <iostream>
#include <map>
#include <exception/ServerError.hpp>
#include <response/Response.hpp>

#include "header/HeaderNormalizer.hpp"

int main()
{
    Zia::Response response;

    Zia::Header header{Zia::Header::ResponseHeader::CACHE_CONTROL, "no-cache"};

    response.addHeader(header);

    try
    {
        throw Zia::ServerError(Zia::Status(Zia::Status::BAD_REQUEST));
    }
    catch (const Zia::ServerError &e)
    {
        /**
         * Catch a Zia::ServerError, should return a response now
         */
        response.setStatus(e.getStatus());
        std::cout << e.what() << std::endl;
    }
    catch (const Zia::Exception &e)
    {
        /**
         * Catch a Zia::Exception, should return a 500 response now
         */
        response.setStatus(Zia::Status(Zia::Status::INTERNAL_SERVER_ERROR));
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        /**
         * Catch a std::exception, should stop the server
         */
        std::cout << e.what() << std::endl;
    }

    // RENDER THE RESPONSE
    return 0;
}