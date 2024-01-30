#ifndef LINK_HANDLER_H
#define LINK_HANDLER_H

#include "cocos2d.h"

class LinkHandler : public cocos2d::CCObject {
public:
    void openLink(CCObject* pSender) {
        cocos2d::CCApplication::sharedApplication()->openURL("https://twitter.com/robtopgames");
    }
};

#endif // LINK_HANDLER_H