#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T09:56:02
#
#-------------------------------------------------

QT       += core gui network sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = qt_open_icon
TEMPLATE = app

INCLUDEPATH += font core utils common test\
utils/label utils/button utils/animation\
utils/dialog utils/timeset \
utils/wheel utils/navbar utils/table\
utils/desktop utils/desktop/procedure \
utils/digitalinput utils/progressbar\
service service/database service/database/connectionpool\
service/database/dao service/database/entity\
service/database/logic\
utils/titlebar utils/animationlist

#DEFINES += RUN_EMBEDDED  #是否运行于嵌入式设备


win32:msvc{
#    CONFIG +=c++11
}else{
#    QMAKE_CXXFLAGS += -std=c++11
    QMAKE_CXXFLAGS += -Wunused-function
    QMAKE_CXXFLAGS += -Wunused-parameter
    QMAKE_CXXFLAGS += -Wreorder
    QMAKE_CXXFLAGS += -Wswitch
}

SOURCES += main.cpp\
    core/iconhelper.cpp \
    font/abstractfont.cpp \
    font/fontawesomewebfont.cpp \
    font/muifont.cpp \
    utils/button/basebutton.cpp \
    utils/button/buttontest.cpp \
    utils/button/switchbutton.cpp \
    utils/button/batterybutton.cpp \
    utils/animation/abstractanimation.cpp \
    utils/animation/animationcenter.cpp \
    utils/animation/animationcover.cpp \
    utils/animation/animationfly.cpp \
    utils/animation/animationsharp.cpp \
    utils/animation/animationslide.cpp \
    utils/animation/animationtest.cpp \
    utils/animation/animationwidget.cpp \
    utils/dialog/toast.cpp \
    utils/dialog/dialogtest.cpp \
    utils/label/baselabel.cpp \
    font/timefont.cpp \
    utils/navbar/navbar.cpp \
    utils/dialog/basemessagebox.cpp \
    common/utilscommon.cpp \
    utils/desktop/desktop.cpp \
    utils/desktop/procedure/qqprocedure.cpp \
    utils/desktop/procedure/procedure.cpp \
    service/database/connectionpool/connectionpool.cpp \
    service/database/dao/abstractdao.cpp \
    service/database/dao/studentdaoimpl.cpp \
    service/database/entity/studentdata.cpp \
    utils/table/baselist.cpp \
    utils/table/listtest.cpp \
    utils/table/normallist.cpp \
    utils/table/linedelegate.cpp \
    utils/table/navlist.cpp \
    utils/digitalinput/digitalinput.cpp \
    utils/digitalinput/digitalinputtest.cpp \
    utils/button/groupbutton.cpp \
    common/global.cpp \
    utils/radiobutton/radiobutton.cpp \
    utils/progressbar/progressbar2.cpp \
    test/mainwindow.cpp \
    utils/label/labeltest.cpp \
    utils/navbar/navbartest.cpp \
    utils/titlebar/titlebar.cpp \
    utils/animationlist/mylistwidget.cpp \
    utils/animationlist/mylistwidgetitem.cpp \
    service/database/logic/databasewig.cpp

HEADERS  += \
    core/iconhelper.h \
    font/abstractfont.h \
    font/fontawesomewebfont.h \
    font/muifont.h \
    utils/button/basebutton.h \
    utils/button/buttontest.h \
    utils/button/switchbutton.h \
    utils/button/batterybutton.h \
    utils/animation/abstractanimation.h \
    utils/animation/animation.h \
    utils/animation/animationcenter.h \
    utils/animation/animationcover.h \
    utils/animation/animationfly.h \
    utils/animation/animationsharp.h \
    utils/animation/animationslide.h \
    utils/animation/animationtest.h \
    utils/animation/animationwidget.h \
    utils/animationlist/mylistwidgetitem.h \
    utils/animationlist/mylistwidget.h \
    utils/dialog/toast.h \
    utils/dialog/dialogtest.h \
    utils/label/baselabel.h \
    font/timefont.h \
    utils/navbar/navbar.h \
    utils/dialog/basemessagebox.h \
    common/utilscommon.h \
    utils/desktop/desktop.h \
    utils/desktop/procedure/qqprocedure.h \
    utils/desktop/procedure/procedure.h \
    utils/desktop/desktopcmd.h \
    utils/desktop/procedure/procedurehead.h \
    service/database/connectionpool/connectionpool.h \
    service/database/dao/abstractdao.h \
    service/database/dao/studentdaoimpl.h \
    service/database/entity/studentdata.h \
    utils/table/baselist.h \
    utils/table/listtest.h \
    utils/table/normallist.h \
    utils/table/linedelegate.h \
    utils/table/navlist.h \
    utils/digitalinput/digitalinput.h \
    utils/digitalinput/digitalinputtest.h \
    utils/button/groupbutton.h \
    common/global.h \
    utils/radiobutton/radiobutton.h \
    utils/progressbar/progressbar2.h \
    test/mainwindow.h \
    utils/label/labeltest.h \
    utils/navbar/navbartest.h \
    utils/titlebar/titlebar.h \
    service/database/logic/databasewig.h
    common/platformhead.h

RESOURCES += \
    resource.qrc

QT_VER_STRING = $$[QT_VERSION];
QT_VER_STRING = $$split(QT_VER_STRING, ".")
QT_VER_MAJOR = $$member(QT_VER_STRING, 0)
QT_VER_MINOR = $$member(QT_VER_STRING, 1)
QT_VER_PATCH = $$member(QT_VER_STRING, 2)


equals(QT_VER_MAJOR, 5){
    HEADERS += \
        utils/timeset/headutils.h \
        utils/timeset/timetotal.h \
        utils/timeset/timedisplay.h \
        utils/timeset/switchwidget.h \
        utils/timeset/timeset.h \
        utils/timeset/zoneset.h \
        utils/timeset/zonetable.h \
        utils/wheel/wheelwidget.h \
        utils/wheel/stringwheelwidget.h \
        utils/wheel/wheeltest.h

    SOURCES += \
        utils/timeset/headutils.cpp \
        utils/timeset/timetotal.cpp \
        utils/timeset/timedisplay.cpp \
        utils/timeset/switchwidget.cpp \
        utils/timeset/timeset.cpp \
        utils/timeset/zoneset.cpp \
        utils/timeset/zonetable.cpp \
        utils/wheel/wheelwidget.cpp \
        utils/wheel/stringwheelwidget.cpp \
        utils/wheel/wheeltest.cpp
}

equals(QT_MAJOR_VERSION, 4){

}


#message(parse over)

FORMS += \
    utils/radiobutton/radiobutton.ui \
    utils/progressbar/progressbar2.ui \
    test/mainwindow.ui \
    utils/label/labeltest.ui \
    utils/navbar/navbartest.ui \
    service/database/logic/databasewig.ui \
    utils/button/buttontest.ui