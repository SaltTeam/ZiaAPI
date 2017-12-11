/**
 * Zia Httpd Server API
 *
 * @authors SaltTeam
 * @date 11/12/2017
 * @package Zia
 */

#ifndef CPP_ZIA_MODEXAMPLE_HPP
#define CPP_ZIA_MODEXAMPLE_HPP


#include "module/IPostRequestModule.hpp"
#include "module/IPostResponseModule.hpp"
#include "module/IPreRequestModule.hpp"
#include "module/IPreResponseModule.hpp"
#include "module/AModule.hpp"

// You simply have to inherit from the different module class to register your hooks
class ModExample : public Zia::Module::AModule,
                   public Zia::Module::IPostRequestModule,
                   public Zia::Module::IPostResponseModule,
                   public Zia::Module::IPreRequestModule,
                   public Zia::Module::IPreResponseModule
{
public:
    bool initialize() override;

    void shutdown() override;

    int getPostRequestWeight() const override;

    Zia::ResponsePtr catchPostRequest(Zia::Request &request) override;

    int getPostResponseWeight() const override;

    void catchPostResponse(std::string &response) override;

    int getPreRequestWeight() const override;

    void catchPreRequest(std::string &request) override;

    int getPreResponseWeight() const override;

    void catchPreResponse(const Zia::Request &request, Zia::Response &response) override;
};


#endif //CPP_ZIA_MODEXAMPLE_HPP
