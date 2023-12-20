TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    globals.cpp \
    book.cpp \
    bookinputscreen.cpp \
    booklist.cpp \
    sellrow.cpp \
    sellrecord.cpp \
    sellinputscreen.cpp \
    expenserecord.cpp \
    expenseinputscreen.cpp \
    annualreport.cpp \
    userinterface.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    globals.h \
    book.h \
    booklist.h \
    bookinputscreen.h \
    sellrow.h \
    sellrecord.h \
    sellinputscreen.h \
    expense.h \
    expenserecord.h \
    expenseinputscreen.h \
    annualreport.h \
    userinterface.h

