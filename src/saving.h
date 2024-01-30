#pragma once

#include <string>
#include <vector>

namespace cocos2d
{
	class CCLayer;
}

namespace Saving
{
	inline bool iconsLoaded = false;
	void saveIcons();
	void loadIcons();
};