cmake_minimum_required(VERSION 3.8.2)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CPP_FLAGS "${CMAKE_CPP_FLAGS} -W -Wall -Wextra")

include(GNUInstallDirs)

project(ZiaAPI VERSION 1.0.0 DESCRIPTION "The SaltTeam API for the Zia project")

set(API_SOURCE_FILES
    api/includes/exception/Exception.hpp
    api/includes/exception/ServerError.hpp
    api/includes/utils/TextUtils.hpp
    api/includes/module/IModule.hpp
    api/includes/module/AModule.hpp
    api/includes/module/IPreRequestModule.hpp
    api/includes/module/IPostRequestModule.hpp
    api/includes/module/IPreResponseModule.hpp
    api/includes/module/IPostResponseModule.hpp
    api/includes/response/Content.hpp
    api/includes/response/Status.hpp
    api/includes/response/Response.hpp
    api/includes/header/Header.hpp
    api/includes/header/HeaderWrapper.hpp
    api/includes/header/HeaderNormalizer.hpp
    api/includes/request/Request.hpp
    api/includes/request/ConstRequest.hpp
    api/includes/session/Session.hpp
    api/includes/ziapi.hpp

    api/sources/exception/Exception.cpp
    api/sources/exception/ServerError.cpp
    api/sources/utils/TextUtils.cpp
    api/sources/modules/AModule.cpp
    api/sources/response/Content.cpp
    api/sources/response/Status.cpp
    api/sources/response/Response.cpp
    api/sources/header/Header.cpp
    api/sources/header/HeaderWrapper.cpp
    api/sources/header/HeaderNormalizer.cpp
    api/sources/request/Request.cpp
    api/sources/request/ConstRequest.cpp
    api/sources/session/Session.cpp
    )

include_directories(api/includes)

add_library(ziapi SHARED ${API_SOURCE_FILES})
set_target_properties(ziapi PROPERTIES
                      VERSION ${PROJECT_VERSION}
                      SOVERSION 1
                      PUBLIC_HEADER api/includes/ziapi.hpp
                      )
configure_file(ziapi.pc.in ziapi.pc @ONLY)
target_include_directories(ziapi PRIVATE api/includes)

install(TARGETS ziapi
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/ziapi.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)