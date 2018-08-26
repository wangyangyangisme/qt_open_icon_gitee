#ifndef ICONHELPER_H
#define ICONHELPER_H

#include "abstractfont.h"

/**
 * @brief 使用字体库核心类
 */
class IconHelper:public QObject
{
    Q_OBJECT

public:
    //运用单例模式，保证只有一个实体
    static IconHelper* Instance()
    {
        static QMutex mutex;
        if(!_instance)
        {
            QMutexLocker locker(&mutex);
            if(!_instance)
            {
                _instance=new IconHelper;
            }
        }
        return _instance;
    }
    void setNewIcon(const AbstractFont &newFont);
    QFont getFont()const{return iconFont;}

private:
    explicit IconHelper();
    static IconHelper *_instance;
    QFont iconFont;
};

namespace iconhelp {  //名字空间

//核心non-member模板函数，会设置wig窗体显示当前字体库中第iconIndex代表的字符
template<typename WidgetType>
void setIcon(WidgetType *wig, int iconIndex)
{
    QChar c(iconIndex);
    wig->setFont(IconHelper::Instance()->getFont());
    wig->setText(c);
}

}

#endif // ICONHELPER_H
