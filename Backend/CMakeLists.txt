cmake_minimum_required(VERSION 3.16)

project(NutritionServer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets HttpServer)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets HttpServer Concurrent)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})


set(PROJECT_SOURCES
        mainwindow.h
        main.cpp
        mainwindow.cpp
        mainwindow.ui
        nutritionserver.h
        nutritionserver.cpp
        system_monitor_widget.h system_monitor_widget.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(NutritionServer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        patient.h patient.cpp
        patient_service.h patient_service.cpp
        bmi_calculator.h bmi_calculator.cpp
        metric_bmi_strategy.h metric_bmi_strategy.cpp
        imperial_bmi_strategy.h imperial_bmi_strategy.cpp
        bmr_calculator.h bmr_calculator.cpp
        harrisbenedict_bmr_strategy.h harrisbenedict_bmr_strategy.cpp
        mifflinstjeor_bmr_strategy.h mifflinstjeor_bmr_strategy.cpp
        food_item.h food_item.cpp
        diet_plan.h diet_plan.cpp
        diet_plan_service.h diet_plan_service.cpp
        json_highlighter.cpp
        json_highlighter.h

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET NutritionServer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(NutritionServer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(NutritionServer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(NutritionServer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(NutritionServer PRIVATE Qt${QT_VERSION_MAJOR}::HttpServer)
target_link_libraries(NutritionServer PRIVATE Qt${QT_VERSION_MAJOR}::Concurrent)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.NutritionServer)
endif()
set_target_properties(NutritionServer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS NutritionServer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(NutritionServer)
endif()
