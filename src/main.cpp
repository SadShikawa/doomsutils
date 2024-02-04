
#include <Geode/Geode.hpp>

#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/GameStatsManager.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/OptionsLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>
#include <Geode/utils/web.hpp>
#include <UIBuilder.hpp>
#include "LinkHandler.h"
#include "saving.h"


using namespace geode::prelude;
static geode::Loader* get();
class $modify(MenuLayer) {
	bool init() {
		if(!MenuLayer::init()) return false;


		// save icons
		if(Saving::iconsLoaded)
			Saving::saveIcons();
		
		Saving::loadIcons();

		auto winSize = CCDirector::get()->getWinSize(); // windows size mhm
		auto socialmediamenu = this->getChildByID("social-media-menu"); // get social media menu thing

		// edits social menu by deleting some stuff and scaling it down a bit
		socialmediamenu->removeChildByID("robtop-logo-button");
		socialmediamenu->removeChildByID("youtube-button");
		socialmediamenu->removeChildByID("twitch-button");
		socialmediamenu->setScale(0.9);
		// get discord
		auto discordbutton = socialmediamenu->getChildByID("discord-button");
		// move discord button and social media menu parent
		discordbutton->setPosition(30, 30);
		socialmediamenu->setPosition(30, -20);
		
		// moves the player button thing with username
		auto profilemenu = this->getChildByID("profile-menu");
		profilemenu->setPosition(107, 68);

		auto profilename = this->getChildByID("player-username");
		profilename->setPosition(61, 105);


		// remove more games
		auto moregamesmenu = this->getChildByID("more-games-menu");
		moregamesmenu->getChildByID("more-games-button")->setVisible(false);


		// CHANG twitter
		
		if(Mod::get()->getSettingValue<bool>("old-twitter-icon") == false) {
			// create vars for buttns idk
			auto xButton = socialmediamenu->getChildByID("twitter-button");


			LinkHandler* lh = new LinkHandler();
			auto spr = CCSprite::create("DU_twitterBtn.png"_spr);
			auto btn = CCMenuItemSpriteExtra::create(spr, socialmediamenu, lh, menu_selector(LinkHandler::openLink));


			btn->setPosition(ccp(1.5f, 30.0f));
			spr->setScale(0.825f);

			xButton->removeFromParentAndCleanup(true);
			btn->setID("new-twitter-button");
			socialmediamenu->addChild(btn);

		};

		// get settings stuff
		auto mainmenubutton = Mod::get()->getSettingValue<bool>("main-menu");

		if (mainmenubutton == true){
			auto create = Build<CCSprite>::createSpriteName("GJ_createBtn_001.png")
				.intoMenuItem([](auto target) {
					CreatorLayer::create()->onMyLevels(target);
				})
				.scale(0.75f)
				.pos(30, 20)
				.parent(moregamesmenu)
				.id("create-menu"_spr);
		}
		else {
			auto create = Build<CCSprite>::createSpriteName("GJ_searchBtn_001.png")
				.intoMenuItem([](auto target) {
					CreatorLayer::create()->onOnlineLevels(target);
				})
				.scale(0.75f)
				.pos(30, 20)
				.parent(moregamesmenu)
				.id("search-menu"_spr);
		}

		moregamesmenu->updateLayout();
		socialmediamenu->updateLayout();
		return true;
	};
};    




// icon hack aka more stealing thanks whoever made this
class $modify (GameStatsManager) {

	bool isItemUnlocked(UnlockType type, int id)
	{

		if (type == UnlockType::GJItem)
		{
			if (id == 18 || id == 20) // ???????????????????
				return false;
		}
		
		if (id == 16 && Mod::get()->getSettingValue<bool>("music-customizer-hack") == true) // music customizer
		{ 
			return true; 
		}
		else if (id == 17 && Mod::get()->getSettingValue<bool>("practice-music-hack") == true) // practice music hack
		{
			return true;
		}

	}
};

class $modify(GameManager) {

	bool isIconUnlocked(int id, IconType type) {
		if (Mod::get()->getSettingValue<bool>("icon-hack") == true) {
	   		return true; }
		else {
		return GameManager::isIconUnlocked(id, type);
		}
	}

	bool isColorUnlocked(int id, UnlockType type) {
		if (Mod::get()->getSettingValue<bool>("icon-hack") == true) {
	   		return true; }
		else {
		return GameManager::isColorUnlocked(id, type);
		}
	}
};