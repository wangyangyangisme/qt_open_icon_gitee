#ifndef MUIFONT_H
#define MUIFONT_H

#include "abstractfont.h"

class MuiFont : public AbstractFont
{
public:
    //随用随加
    enum ICON_INDEX{
        ICON_WEINXIN = 0xe261,
        ICON_PENGYOUQUAN = 0xe262,
        ICON_QQ = 0xe264,
        ICON_PLUS = 0xe409,
        ICON_MINUS = 0xe410,
        ICON_BARS = 0xe563,
        ICON_BACK = 0xe471,
    };
    explicit MuiFont();
};

#endif // MUIFONT_H
