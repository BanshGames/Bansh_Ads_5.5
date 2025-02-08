// Copyright Bansh Games 2022, All Rights Reserved.

#pragma once

#include "UObject/NoExportTypes.h"
#include "AdMobSetting.generated.h"

/** AdMob TagForChildDirectedTreament  */
UENUM()
namespace ETagForChildDirectedTreatment_AdMob
{
	enum Type : int
	{
		TAG_FOR_CHILD_DIRECTED_TREATMENT_UNSPECIFIED = 0,
		TAG_FOR_CHILD_DIRECTED_TREATMENT_TRUE = 1,
		TAG_FOR_CHILD_DIRECTED_TREATMENT_FALSE = 2,
	};
}

/** AdMob TagForChildDirectedTreament  */
UENUM()
namespace ETagForUnderAgeOfConsent_AdMob
{
	enum Type : int
	{
		TAG_FOR_UNDER_AGE_OF_CONSENT_UNSPECIFIED = 0,
		TAG_FOR_UNDER_AGE_OF_CONSENT_TRUE = 1,
		TAG_FOR_UNDER_AGE_OF_CONSENT_FALSE = 2,
	};
}

/** AdMob MaxAdContentRating  */
UENUM()
namespace EMaxAdContentRating_AdMob
{
	enum Type : int
	{
		MAX_AD_CONTENT_RATING_G = 0,
		MAX_AD_CONTENT_RATING_PG = 1,
		MAX_AD_CONTENT_RATING_T = 2,
		MAX_AD_CONTENT_RATING_MA = 3,
	};
}

/**
 *
 */
UCLASS(globaluserconfig, config = Engine)
class UAdMobSetting : public UObject
{
	GENERATED_BODY()

	// Set true to add AdMob for android
	UPROPERTY(Config, EditAnywhere, Category = SupportPlatform, Meta = (DisplayName = "Android"))
	bool bAndroidEnabled;

	// Add Android test device ID (currently unusable)
	UPROPERTY(Config, EditAnywhere, Category = AdMobSettings, Meta = (DisplayName = "Test Device ID"))
	FString testDeviceID;

	// the android admob appid | e.g. (ca-app-pub-XXXXXXXXXXXXXXXX~YYYYYYYYYY)
	UPROPERTY(Config, EditAnywhere, Category = AdMobSettings, Meta = (DisplayName = "AdMob App ID"))
	FString AppId;

	// the banner adunit | e.g. (ca-app-pub-XXXXXXXXXXXXXXXX/YYYYYYYYYY)
	UPROPERTY(Config, EditAnywhere, Category = AdMobSettings, Meta = (DisplayName = "Banner Ad IDs"))
	TArray<FString> AndroidBannerUnit;

	// the interstitial adunits | e.g. (ca-app-pub-XXXXXXXXXXXXXXXX/YYYYYYYYYY)
	UPROPERTY(Config, EditAnywhere, Category = AdMobSettings, Meta = (DisplayName = "Interstitial Ad IDs"))
	TArray<FString> AndroidInterstitialUnit;

	// the rewarded video adunits | e.g. (ca-app-pub-XXXXXXXXXXXXXXXX/YYYYYYYYYY)
	UPROPERTY(Config, EditAnywhere, Category = AdMobSettings, Meta = (DisplayName = "RewardVideo Ad IDs"))
	TArray<FString> AndroidRewardedVideoAdUnit;

	// Set true to Enable the user consent form
	UPROPERTY(Config, EditAnywhere, Category = SupportPlatform, Meta = (DisplayName = "User Consent form (CCPA,GDPR)"))
	bool bUserConsent;

	// Admob TagForChildDirectedTreatment (see https://developers.google.com/admob/android/targeting)
	UPROPERTY(Config, EditAnywhere, Category = AdControl, meta = (DisplayName = "AdMob Tag For Child-Directed Treatment"), meta = (EditCondition = "bAndroidEnabled"), meta = (ToolTip = "Admob TagForChildDirectedTreatment (see https://developers.google.com/admob/android/targeting)"))
	TEnumAsByte<ETagForChildDirectedTreatment_AdMob::Type> TagForChildDirectedTreatment;

	// Admob TagForUnderAgeOfConsent (see https://developers.google.com/admob/android/targeting)
	UPROPERTY(Config, EditAnywhere, Category = AdControl, meta = (DisplayName = "AdMob Tag For Under Age Of Consent"), meta = (EditCondition = "bAndroidEnabled"), meta = (ToolTip = "Admob TagForUnderAgeOfConsent (see https://developers.google.com/admob/android/targeting)"))
	TEnumAsByte<ETagForUnderAgeOfConsent_AdMob::Type> TagForUnderAgeOfConsent;

	// Admob MaxAdContentRating (see https://developers.google.com/admob/android/targeting)
	UPROPERTY(Config, EditAnywhere, Category = AdControl, meta = (DisplayName = "AdMob Max ad content rating"), meta = (EditCondition = "bAndroidEnabled"), meta = (ToolTip = "Admob MaxAdContentRating (see https://developers.google.com/admob/android/targeting)"))
	TEnumAsByte<EMaxAdContentRating_AdMob::Type> MaxAdContentRating;

	// Set true to enable Mediation for android
	UPROPERTY(Config, EditAnywhere, Category = Mediation, Meta = (DisplayName = "Mediation is Enable"))
	bool bMediationEnable;

	// the AppLovin Mediation
	UPROPERTY(Config, EditAnywhere, Category = Mediation, Meta = (DisplayName = "AppLovin", EditCondition = "bMediationEnable"))
	bool bAppLovinEnable;

	// the CharBoost mediation
	//UPROPERTY(Config, EditAnywhere, Category = Mediation, Meta = (DisplayName = "Chart Boost", EditCondition = "bMediationEnable"))
	//bool bChartBoostEnable;

	// the AdColony Mediation
	UPROPERTY(Config, EditAnywhere, Category = Mediation, Meta = (DisplayName = "AdColony", EditCondition = "bMediationEnable"))
	bool bAdColonyEnable;

	// the Meta(Facebook) Mediation | automatic disable for family policy
	UPROPERTY(Config, EditAnywhere, Category = Mediation, Meta = (DisplayName = "Meta (Facebook)", EditCondition = "bMediationEnable"))
	bool bMetaEnable;

	// the UnityAds Mediation
	UPROPERTY(Config, EditAnywhere, Category = Mediation, Meta = (DisplayName = "Unity Ads", EditCondition = "bMediationEnable"))
	bool bUnityAds;

#if WITH_EDITOR

	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent &PropertyChangedEvent) override;
#endif
};
