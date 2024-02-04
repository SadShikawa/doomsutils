
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "Settings.hpp"
#include "saving.h"

using namespace geode::prelude;

void Saving::saveIcons()
{
	Mod::get()->setSavedValue<int>("icons/cube", GameManager::get()->m_playerFrame);
	Mod::get()->setSavedValue<int>("icons/ship", GameManager::get()->m_playerShip);
	Mod::get()->setSavedValue<int>("icons/ball", GameManager::get()->m_playerBall);
	Mod::get()->setSavedValue<int>("icons/ufo", GameManager::get()->m_playerBird);
	Mod::get()->setSavedValue<int>("icons/wave", GameManager::get()->m_playerDart);
	Mod::get()->setSavedValue<int>("icons/robot", GameManager::get()->m_playerRobot);
	Mod::get()->setSavedValue<int>("icons/spider", GameManager::get()->m_playerSpider);
	Mod::get()->setSavedValue<int>("icons/swing", GameManager::get()->m_playerSwing);
	Mod::get()->setSavedValue<int>("icons/color", GameManager::get()->m_playerColor);
	Mod::get()->setSavedValue<int>("icons/color2", GameManager::get()->m_playerColor2);
	Mod::get()->setSavedValue<int>("icons/colorglow", GameManager::get()->m_playerGlowColor);
	Mod::get()->setSavedValue<int>("icons/streak", GameManager::get()->m_playerStreak);
	Mod::get()->setSavedValue<int>("icons/shipfire", GameManager::get()->m_playerShipFire);
	Mod::get()->setSavedValue<int>("icons/death", GameManager::get()->m_playerDeathEffect);
	Mod::get()->setSavedValue<int>("icons/jetpack", GameManager::get()->m_playerJetpack);
	Mod::get()->setSavedValue<int>("icons/glow", GameManager::get()->m_playerGlow);
}

void Saving::loadIcons()
{
	iconsLoaded = true;
	GameManager::get()->m_playerFrame = Settings::get<int>("icons/cube", GameManager::get()->m_playerFrame);
	GameManager::get()->m_playerShip = Settings::get<int>("icons/ship", GameManager::get()->m_playerShip);
	GameManager::get()->m_playerBall = Settings::get<int>("icons/ball", GameManager::get()->m_playerBall);
	GameManager::get()->m_playerBird = Settings::get<int>("icons/ufo", GameManager::get()->m_playerBird);
	GameManager::get()->m_playerDart = Settings::get<int>("icons/wave", GameManager::get()->m_playerDart);
	GameManager::get()->m_playerRobot = Settings::get<int>("icons/robot", GameManager::get()->m_playerRobot);
	GameManager::get()->m_playerSpider = Settings::get<int>("icons/spider", GameManager::get()->m_playerSpider);
	GameManager::get()->m_playerSwing = Settings::get<int>("icons/swing", GameManager::get()->m_playerSwing);
	GameManager::get()->m_playerColor = Settings::get<int>("icons/color", GameManager::get()->m_playerColor);
	GameManager::get()->m_playerColor2 = Settings::get<int>("icons/color2", GameManager::get()->m_playerColor2);
	GameManager::get()->m_playerGlowColor = Settings::get<int>("icons/colorglow", GameManager::get()->m_playerGlowColor);
	GameManager::get()->m_playerStreak = Settings::get<int>("icons/streak", GameManager::get()->m_playerStreak);
	GameManager::get()->m_playerShipFire = Settings::get<int>("icons/shipfire", GameManager::get()->m_playerShipFire);
	GameManager::get()->m_playerDeathEffect = Settings::get<int>("icons/death", GameManager::get()->m_playerDeathEffect);
	GameManager::get()->m_playerJetpack = Settings::get<int>("icons/jetpack", GameManager::get()->m_playerJetpack);
	GameManager::get()->m_playerDeathEffect = Settings::get<int>("icons/death", GameManager::get()->m_playerDeathEffect);
	GameManager::get()->m_playerJetpack = Settings::get<int>("icons/jetpack", GameManager::get()->m_playerJetpack);
	GameManager::get()->m_playerGlow = Settings::get<int>("icons/glow", GameManager::get()->m_playerGlow);
}
// tell maxnut his saving code works well
// nvm had to fix