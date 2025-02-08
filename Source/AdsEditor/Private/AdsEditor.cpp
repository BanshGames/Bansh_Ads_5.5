// Copyright Bansh Games 2022, All Rights Reserved.

#include "AdsEditor.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "PropertyEditorModule.h"
#include "AdMobSetting.h"
#include "ISettingsModule.h"

#include "LevelEditor.h"

static const FName AdsEditorTabName("AdsEditor");

#define LOCTEXT_NAMESPACE "FAdsEditorModule"

void FAdsEditorModule::StartupModule()
{
	ISettingsModule *SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{

		SettingsModule->RegisterSettings("Project", "Plugins ", "AdMob",
										 LOCTEXT("header", "AdMob"),
										 LOCTEXT("discription", "Elevate your Unreal Engine projects with our AdMob Ads Integration & Mediation plugin.\nA tool designed to effortlessly integrate Google AdMob ads into your Android applications.\nBy becoming our Patron at (patreon.com/BanshGames),\nI can:- Accelerate Development- Expand Compatibility- And much more!"),
										 GetMutableDefault<UAdMobSetting>());
	}
}

void FAdsEditorModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAdsEditorModule, AdsEditor)
