QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    depart_m.cpp \
    dept_v.cpp \
    user.cpp \
    widget.cpp \
    main.cpp \
    person_data_maintenance.cpp \
    person_data_query.cpp \
    person_m.cpp \
    salary_m.cpp \
    user_v.cpp \
    login_m.cpp
HEADERS += \
    depart_m.h \
    dept_v.h \
    user.h \
    widget.h \
    person_data_maintenance.h \
    person_data_query.h \
    person_m.h \
    salary_m.h \
    user_v.h \
    login_m.h

FORMS += \
    depart_m.ui \
    dept_v.ui \
    user.ui \
    widget.ui \
    person_data_maintenance.ui \
    person_data_query.ui \
    person_m.ui \
    salary_m.ui \
    user_v.ui \
    login_m.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rec.qrc
