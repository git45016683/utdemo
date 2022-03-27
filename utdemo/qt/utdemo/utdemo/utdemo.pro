QT += core
QT -= gui

CONFIG += c++11

TARGET = utdemo
CONFIG += console
CONFIG -= app_bundle
CONFIG += warn_off

TEMPLATE = app

#remove -fpermissive warning/error
#QMAKE_CXXFLAGS += -fpermissive -shared -fpack-struct=1 -fPIC  -g
#QMAKE_CFLAGS += -fpermissive -shared -fpack-struct=1 -fPIC  -g
QMAKE_CXXFLAGS += -fpermissive -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fpermissive -fprofile-arcs -ftest-coverage
DEFINES += UT

INCLUDEPATH += \
        ../../../../demo/model \
        ../../../../demo/model/device \
        ../../../../demo/model/device/hardware \
        ../../../../demo/model/device/hardware/com \
        ../../../../demo/model/device/hardware/usb\
        ../../../../demo/model/network \
        ../../../src/gtest/head \
        ../../../src/gtest/gmock/head \
        ../../../src/gtest/cppfreemock \
        ../../../src/head


HEADERS += \
        ../../../../demo/model/model.h \
        ../../../../demo/model/device/device.h \
        ../../../../demo/model/device/hardware/hardware.h \
        ../../../../demo/model/device/hardware/com/com.h \
        ../../../../demo/model/device/hardware/usb/usb.h \
        ../../../../demo/model/network/network.h \
        ../../../src/head/test_model.h


SOURCES += \
        main.cpp \
        ../../../../demo/model/model.cpp \
        ../../../../demo/model/device/device.cpp \
        ../../../../demo/model/device/hardware/com/com.cpp \
        ../../../../demo/model/device/hardware/usb/usb.cpp \
        ../../../../demo/model/network/network.cpp \
        ../../../src/test_src/test_normal.cpp \
        ../../../src/test_src/test_model.cpp


LIBS += -L../../../src/gtest/lib \
        -L../../../src/gtest/gmock/lib \
-lgtest \
-lgmock \
-ldl \
-lpthread \
-lgcov



