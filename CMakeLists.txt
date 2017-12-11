project(cpp_zia)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -W -Wall -Wextra -Werror -ggdb3")

cmake_minimum_required(VERSION 3.8.2)
set(SOURCE_FILES

        api/includes/exception/Exception.hpp
        api/includes/exception/ServerError.hpp
        api/includes/utils/TextUtils.hpp
        api/includes/module/IModule.hpp
        api/includes/module/AModule.hpp
        api/includes/module/IPreRequestModule.hpp
        api/includes/module/IPostRequestModule.hpp
        api/includes/module/IPreResponseModule.hpp
        api/includes/module/IPostResponseModule.hpp
        api/includes/response/Response.hpp
        api/includes/response/Content.hpp
        api/includes/response/Status.hpp
        api/includes/header/Header.hpp
        api/includes/header/HeaderWrapper.hpp
        api/includes/header/HeaderNormalizer.hpp
        api/includes/request/Request.hpp

        api/sources/exception/Exception.cpp
        api/sources/exception/ServerError.cpp
        api/sources/main.cpp
        api/sources/utils/TextUtils.cpp
        api/sources/modules/AModule.cpp
        api/sources/response/Content.cpp
        api/sources/response/Status.cpp
        api/sources/response/Response.cpp
        api/sources/header/Header.cpp
        api/sources/header/HeaderWrapper.cpp
        api/sources/header/HeaderNormalizer.cpp
        api/sources/request/Request.cpp

        example/ModExample.hpp
        example/ModExample.cpp
        )
include_directories(api/includes)
add_executable(cpp_zia ${SOURCE_FILES})
target_link_libraries(cpp_zia)
