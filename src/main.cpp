
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
		if(Loader::get()->isModLoaded("skyward.no_robtop_logo") == false){
			socialmediamenu->removeChildByID("robtop-logo-button");
			socialmediamenu->removeChildByID("youtube-button");
			socialmediamenu->removeChildByID("twitch-button");
			socialmediamenu->setScale(0.9);
			// get discord
			auto discordbutton = socialmediamenu->getChildByID("discord-button");
			// get fb
			auto fbbutton = socialmediamenu->getChildByID("facebook-button");
			// get twitter
			auto twitterbutton = socialmediamenu->getChildByID("twitter-button");
			// move discord button and social media menu parent
			discordbutton->setPosition(30, 30);
			fbbutton->setPosition(-27, 30);
			twitterbutton->setPosition(1.5, 30);
			socialmediamenu->setPosition(59, -6);
		}
		
		// moves the player button thing with username
		auto profilemenu = this->getChildByID("profile-menu");
		profilemenu->setPosition(107, 68);

		auto profilename = this->getChildByID("player-username");
		profilename->setPosition(61, 105);


		auto moregamesmenu = this->getChildByID("more-games-menu");



		// CHANG twitter
		
		if(Mod::get()->getSettingValue<bool>("old-twitter-icon") == false) {
				// create vars for buttns idk
			auto xButton = socialmediamenu->getChildByID("twitter-button");
			LinkHandler* lh = new LinkHandler();
			auto spr = CCSprite::create("DU_twitterBtn.png"_spr);
			auto btn = CCMenuItemSpriteExtra::create(spr, socialmediamenu, lh, menu_selector(LinkHandler::openLink));
			if(Loader::get()->isModLoaded("skyward.no_robtop_logo") == false){

				btn->setPosition(ccp(1.5f, 30.0f));
				spr->setScale(0.825f);

			}else{

				btn->setPosition(ccp(41.6f, 39.6f));
				spr->setScale(0.825f);
			}

			xButton->removeFromParentAndCleanup(true);
			btn->setID("new-twitter-button");
			socialmediamenu->addChild(btn);
		};

		// shortcut button

		auto shortcutmenu = Build<CCMenu>::create()
			.pos(winSize.width - 200, 12)
			.scale(0.75f)
			.contentSize({250.000f, 104.500f})
			.anchorPoint({0, 0})
			.parent(this)
			.layout(
				RowLayout::create()
				->setAxisAlignment(AxisAlignment::End)
				->setGrowCrossAxis(true)
				->setAxisReverse(true)
				)
			.id("shortcut-menu"_spr)
			.collect();
			bool Size = false;
		if (Mod::get()->getSettingValue<bool>("main-menu")) {
			auto Button = Build<CCSprite>::createSpriteName("GJ_createBtn_001.png")
				.intoMenuItem([](auto target) {
					CreatorLayer::create()->onSavedLevels(target);
				})
				.pos(0, 0)
				.parent(shortcutmenu)
				.id("create-menu"_spr);
		}
		else {
			auto Button = Build<CCSprite>::createSpriteName("GJ_searchBtn_001.png")
				.intoMenuItem([](auto target) {
					CreatorLayer::create()->onOnlineLevels(target);
				})
				.pos(0, 0)
				.parent(shortcutmenu)
				.id("search-menu"_spr);
		}
		// remove more games
		if(Loader::get()->isModLoaded("blackholemx.nomoregames") == false) {
			moregamesmenu->getChildByID("more-games-button")->removeFromParentAndCleanup(true);
		}

		moregamesmenu->updateLayout();
		socialmediamenu->updateLayout();
		shortcutmenu->updateLayout();
		return true;
	};
};    




// icon hack aka more stealing thanks whoever made this
class $modify (GameStatsManager) {

	bool isItemUnlocked(UnlockType type, int id)
	{

		if (type == UnlockType::GJItem)
		{
			if ((id == 18 || id == 20) && Mod::get()->getSettingValue<bool>("icon-hack") == true) // ???????????????????
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