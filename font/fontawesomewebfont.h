#ifndef FONTAWESOMEWEBFONT_H
#define FONTAWESOMEWEBFONT_H

#include "abstractfont.h"

class FontawesomeWebfont : public AbstractFont
{
public:
    enum ICON_INDEX{
        ICON_LOCK = 0xf023,
        ICON_UNLOCK = 0xf09c,
        BATTERY_0 = 0xf244,
        BATTERY_1 = 0xf243,
        BATTERY_2 = 0xf242,
        BATTERY_3 = 0xf241,
        BATTERY_4 = 0xf240,
        ICON_CHECK = 0xf00c,
        ICON_WAINING = 0xf071,
        ICON_CLOSE = 0xf00d,
        ICON_INFO = 0xf05a,
        ICON_WINDOW_CLOSE = 0xf00d,
        ICON_WINDOW_MAXIMIZE = 0xf2d0,
        ICON_WINDOW_MINIMIZE = 0xf2d1,
        ICON_WINDOW_RESTORE = 0xf2d2,
        ICON_WINDOW_SIGNAL = 0xf012,
    };
    explicit FontawesomeWebfont();
};

#endif // FONTAWESOMEWEBFONT_H
