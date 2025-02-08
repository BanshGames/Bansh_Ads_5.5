//Copyright Bansh Games 2022, All Rights Reserved.

#include "AdMobSetting.h"
#include "AdsEditor.h"

#if WITH_EDITOR
void UAdMobSetting::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	SaveConfig(CPF_Config, *GetDefaultConfigFilename() );
}
#endif
