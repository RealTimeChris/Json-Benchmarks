set(simdjson_DIR "C:/vcpkg/installed/x64-windows/share/simdjson")
SET(Jsonifier_DIR "C:/users/chris/cmake/jsonifier/share/jsonifier/")
set(fmt_DIR "C:/vcpkg/installed/x64-windows/share/fmt")
cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME "Json-Benchmarks")
set(PRODUCT_VERSION "1.0.0.9")
set(DESCRIPTION "A testing program.")
set(DiscordCoreAPI_DIR "${CMAKE_CONFIG_FILE_DIR}")

project(
	"${PROJECT_NAME}"
	VERSION "${PRODUCT_VERSION}"
	LANGUAGES CXX
	HOMEPAGE_URL "https://github.com/RealTimeChris/Json-Benchmarks"
	DESCRIPTION "${DESCRIPTION}"
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake") 
set(CMAKE_CONFIGURATION_TYPES "${CMAKE_BUILD_TYPE}")

if (WIN32)
	if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
		cmake_path(GET CMAKE_ROOT ROOT_PATH ROOT_DRIVE)
		set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/Output Files/" CACHE PATH "The CMake install prefix." FORCE)
	endif()
elseif(UNIX)
	if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
		set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/Output Files/" CACHE PATH "The CMake install prefix." FORCE)
	endif()
else()
		message(FATAL_ERROR "Sorry, but your OS is not supported!")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}/CMake") 
set(CMAKE_CONFIGURATION_TYPES "${CMAKE_BUILD_TYPE}")

include(FetchContent)
FetchContent_Declare(
    nanobench
	URL https://github.com/martinus/nanobench/archive/refs/tags/v4.3.9.zip
	DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(nanobench)
find_package(fmt CONFIG REQUIRED)    
find_package(Jsonifier CONFIG REQUIRED)
find_package(simdjson CONFIG REQUIRED)
add_subdirectory(Executable)
