// Copyright Bansh Games 2022, All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "AdMobBPLibrary.generated.h"

USTRUCT(BlueprintType)
struct FAdMobRewardItem
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "RewardItem")
	FString type;

	UPROPERTY(BlueprintReadOnly, Category = "RewardItem")
	int32 amount = 0;
};

//-- Dispatchers
DECLARE_DYNAMIC_DELEGATE(FRewardDispatcher);
DECLARE_DYNAMIC_DELEGATE_OneParam(FRewardEarnedDispatcher, FAdMobRewardItem, reward);

UCLASS()
class UAdMobBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	static void ExecuteOnGameThread(TFunction<void()> Function);

public:
	// Delgates to send the return values from java
	static FRewardDispatcher RAL, RAF, ORAS, ORAFS, ORAD;
	static FRewardEarnedDispatcher OUER;
	static void callRewardDelegates(int32 index);
	static void callUserEarnedReward(FString rewardType, int32 amount);
	static FAdMobRewardItem rewardItem;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "BA Show Banner", Keywords = " Show Banner"), Category = "AdMob Advertisiment")
	static void ShowBanner(int32 Index, bool isOnBottom);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "BA Hide Banner", Keywords = " Hide Banner"), Category = "AdMob Advertisiment")
	static void HideBanner();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "BA Close Banner", Keywords = " Close Banner"), Category = "AdMob Advertisiment")
	static void CloseBanner();

	// Interstial Ads functionalities

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "BA Load Interstitial Ad", Keywords = " Load Interstitial Ad"), Category = "AdMob Advertisiment")
	static void LoadInterstitialAd(int32 Index);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "BA Is Interstitial Ads Available", Keywords = " Check Interstital Ads Available"), Category = "AdMob Advertisiment")
	static bool IsInterstitialAdAvailable();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "BA Is Interstitial Ads Requested", Keywords = " Is Interstitial Ads Requested"), Category = "AdMob Advertisiment")
	static bool IsInterstitialAdRequested();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "BA Show Interstitial", Keywords = " Show Interstitial Ads"), Category = "AdMob Advertisiment")
	static void ShowInterstitialAd();

	// Rewarded Ads Functionalities

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "BA Load Rewarded Video", Keywords = "Load Rewarded Video"), Category = "AdMob Advertisiment")
	static void LoadRewardedVideo(int32 Index, const FRewardDispatcher &onRewardedAdLoaded, const FRewardDispatcher &onRewardedAdFailedToLoad);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "BA Is Rewarded Video Available", Keywords = "Is Rewarded Video Available"), Category = "AdMob Advertisiment")
	static bool IsRewardedVideoAvailable();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "BA Is Rewarded Video Requested", Keywords = "Is Rewarded Video Requested "), Category = "AdMob Advertisiment")
	static bool IsRewardedVideoRequested();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "BA Get reward item", Keywords = "get reward item "), Category = "AdMob Advertisiment")
	static FAdMobRewardItem getRewardItem();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "BA Play Rewarded Video", Keywords = "Play Rewarded Video"), Category = "AdMob Advertisiment")
	static void PlayRewardedVideo(const FRewardDispatcher &onRewardedAdShowed, const FRewardDispatcher &onRewardedAdFailedToShow, const FRewardDispatcher &onRewardedAdDismissed, const FRewardEarnedDispatcher &onUserEarnedReward);
};
