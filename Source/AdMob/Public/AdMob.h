//Copyright Bansh Games 2022, All Rights Reserved.
#pragma once

#include "Modules/ModuleManager.h"
#include "AdMobBPLibrary.h"

class FAdMobModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};



