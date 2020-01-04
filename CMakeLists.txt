cmake_minimum_required(VERSION 3.12)
project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 14)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(print_ip)
target_sources(print_ip PRIVATE
        main.cpp
        )

add_library(print_templates INTERFACE)
target_include_directories(print_templates INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_print_ip)
target_sources(test_print_ip PRIVATE
        test_print_ip.cpp
        )

set_target_properties(test_print_ip PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_link_libraries(print_ip
        print_templates
        )

message("BOOST:" ${Boost_LIBRARIES})

target_link_libraries(test_print_ip
        ${Boost_LIBRARIES}
        print_templates
        )

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT tnovits@yandex.ru)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(print_ip_tests test_print_ip)