// Copyright Bansh Games 2022, All Rights Reserved.

#include "AdMobBPLibrary.h"
#include "Misc/ConfigCacheIni.h"
#include "Async/TaskGraphInterfaces.h"
#include "Engine.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

DEFINE_LOG_CATEGORY_STATIC(AdMob, Log, All);

UAdMobBPLibrary::UAdMobBPLibrary(const FObjectInitializer &ObjectInitializer) : Super(ObjectInitializer)
{
}

void UAdMobBPLibrary::ShowBanner(int32 Index, bool bShowOnBottonOfScreen)
{
	TArray<FString> AdUnitIDs;
	int32 count = GConfig->GetArray(TEXT("/Script/AdsEditor.AdMobSetting"), TEXT("AndroidBannerUnit"), AdUnitIDs, GEngineIni);

#if PLATFORM_ANDROID
	if (count != 0 && !AdUnitIDs[Index].IsEmpty())
	{
		if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
		{
			static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowAdBanner_AdMob", "(Ljava/lang/String;Z)V", false);

			FString AdUnitID = AdUnitIDs[Index];
			auto AdUnitIDArg = FJavaHelper::ToJavaString(Env, AdUnitID);
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *AdUnitIDArg, bShowOnBottonOfScreen);
		}
	}

#endif
}

void UAdMobBPLibrary::HideBanner()
{

#if PLATFORM_ANDROID

	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_HideBanner_AdMob", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

void UAdMobBPLibrary::CloseBanner()
{

#if PLATFORM_ANDROID

	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CloseBanner_AdMob", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

// Interstial Ads

void UAdMobBPLibrary::LoadInterstitialAd(int32 Index)
{
	TArray<FString> AdUnitIDs;
	int32 count = GConfig->GetArray(TEXT("/Script/AdsEditor.AdMobSetting"), TEXT("AndroidInterstitialUnit"), AdUnitIDs, GEngineIni);

#if PLATFORM_ANDROID
	if (count != 0 && !AdUnitIDs[Index].IsEmpty())
	{
		if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
		{

			static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_LoadInterstitialAd_AdMob", "(Ljava/lang/String;)V", false);

			auto AdUnitIDArg = FJavaHelper::ToJavaString(Env, AdUnitIDs[Index]);
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *AdUnitIDArg);
		}
	}

#endif
}

bool UAdMobBPLibrary::IsInterstitialAdAvailable()
{
	bool ReturnValue = false;
#if PLATFORM_ANDROID

	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_IsInterstitialAdAvailable_AdMob", "()Z", false);
		ReturnValue = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return ReturnValue;
}

bool UAdMobBPLibrary::IsInterstitialAdRequested()
{
	bool ReturnValue = false;

#if PLATFORM_ANDROID
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_IsInterstitialAdRequested_AdMob", "()Z", false);
		ReturnValue = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return ReturnValue;
}

void UAdMobBPLibrary::ShowInterstitialAd()
{

#if PLATFORM_ANDROID

	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowInterstitialAd_AdMob", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

// Rewarded video Ads

FRewardDispatcher UAdMobBPLibrary::RAL;
FRewardDispatcher UAdMobBPLibrary::RAF;

void UAdMobBPLibrary::LoadRewardedVideo(int32 Index, const FRewardDispatcher &onRewardedAdLoaded, const FRewardDispatcher &onRewardedAdFailedToLoad)
{
	UAdMobBPLibrary::RAL = onRewardedAdLoaded;
	UAdMobBPLibrary::RAF = onRewardedAdFailedToLoad;

	TArray<FString> AdUnitIDs;
	int32 count = GConfig->GetArray(TEXT("/Script/AdsEditor.AdMobSetting"), TEXT("AndroidRewardedVideoAdUnit"), AdUnitIDs, GEngineIni);

#if PLATFORM_ANDROID
	if (count != 0 && !AdUnitIDs[Index].IsEmpty())
	{
		if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
		{

			static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_LoadRewardedVideo_AdMob", "(Ljava/lang/String;)V", false);

			auto AdUnitIDArg = FJavaHelper::ToJavaString(Env, AdUnitIDs[Index]);
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, *AdUnitIDArg);
		}
	}

#endif
}

bool UAdMobBPLibrary::IsRewardedVideoAvailable()
{
	bool ReturnValue = false;
#if PLATFORM_ANDROID

	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_IsRewardedVideoAvailable_AdMob", "()Z", false);
		ReturnValue = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return ReturnValue;
}

bool UAdMobBPLibrary::IsRewardedVideoRequested()
{
	bool ReturnValue = false;

#if PLATFORM_ANDROID
	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_IsRewardedVideoRequested_AdMob", "()Z", false);
		ReturnValue = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
	return ReturnValue;
}

FRewardDispatcher UAdMobBPLibrary::ORAS;
FRewardDispatcher UAdMobBPLibrary::ORAFS;
FRewardDispatcher UAdMobBPLibrary::ORAD;
FRewardEarnedDispatcher UAdMobBPLibrary::OUER;

void UAdMobBPLibrary::PlayRewardedVideo(const FRewardDispatcher &onRewardedAdShowed, const FRewardDispatcher &onRewardedAdFailedToShow, const FRewardDispatcher &onRewardedAdDismissed, const FRewardEarnedDispatcher &onUserEarnedReward)
{
	UAdMobBPLibrary::ORAS = onRewardedAdShowed;
	UAdMobBPLibrary::ORAFS = onRewardedAdFailedToShow;
	UAdMobBPLibrary::ORAD = onRewardedAdDismissed;
	UAdMobBPLibrary::OUER = onUserEarnedReward;

#if PLATFORM_ANDROID

	if (JNIEnv *Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_PlayRewardedVideo_AdMob", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}
#endif
}

//-- Functions CallBack for Java code
#if PLATFORM_ANDROID
JNI_METHOD void Java_com_epicgames_unreal_GameActivity_CPPRewardAd(JNIEnv *env, jclass clazz, jint index)
{

	UAdMobBPLibrary::callRewardDelegates(index);
}

JNI_METHOD void Java_com_epicgames_unreal_GameActivity_CPPUserEarnRewardAd(JNIEnv *env, jclass clazz, jstring rewardType, jint amount)
{

	FString CPPrewardType = FJavaHelper::FStringFromLocalRef(env, rewardType);
	UAdMobBPLibrary::callUserEarnedReward(CPPrewardType, amount);
}

#endif // PLATFORM_ANDROID

//void UAdMobBPLibrary::callRewardDelegates(int32 index)
//{
//
//	switch (index)
//	{
//	case 1:
//		UAdMobBPLibrary::RAL.ExecuteIfBound();
//		break;
//	case 2:
//		UAdMobBPLibrary::RAF.ExecuteIfBound();
//		break;
//	case 3:
//		UAdMobBPLibrary::ORAS.ExecuteIfBound();
//		break;
//	case 4:
//		UAdMobBPLibrary::ORAFS.ExecuteIfBound();
//		break;
//	case 5:
//		UAdMobBPLibrary::ORAD.ExecuteIfBound();
//		break;
//	}
//}

void UAdMobBPLibrary::callRewardDelegates(int32 index)
{
	switch (index)
	{
	case 1:
		UAdMobBPLibrary::ExecuteOnGameThread([]() { RAL.ExecuteIfBound(); });
		break;
	case 2:
		UAdMobBPLibrary::ExecuteOnGameThread([]() { RAF.ExecuteIfBound(); });
		break;
	case 3:
		UAdMobBPLibrary::ExecuteOnGameThread([]() { ORAS.ExecuteIfBound(); });
		break;
	case 4:
		UAdMobBPLibrary::ExecuteOnGameThread([]() { ORAFS.ExecuteIfBound(); });
		break;
	case 5:
		UAdMobBPLibrary::ExecuteOnGameThread([]() { ORAD.ExecuteIfBound(); });
		break;
	}
}

FAdMobRewardItem UAdMobBPLibrary::rewardItem;

void UAdMobBPLibrary::callUserEarnedReward(FString rewardType, int32 amount)
{
	UAdMobBPLibrary::rewardItem.type = rewardType;
	UAdMobBPLibrary::rewardItem.amount = amount;

	//UAdMobBPLibrary::OUER.ExecuteIfBound(UAdMobBPLibrary::rewardItem);
	UAdMobBPLibrary::ExecuteOnGameThread([]() { OUER.ExecuteIfBound(UAdMobBPLibrary::rewardItem); });
}

FAdMobRewardItem UAdMobBPLibrary::getRewardItem()
{
	return UAdMobBPLibrary::rewardItem;
}

void UAdMobBPLibrary::ExecuteOnGameThread(TFunction<void()> Function)
{
	if (!GEngine)
		return;

	// Dispatch the function to run on the game thread
	FFunctionGraphTask::CreateAndDispatchWhenReady(
		[Function]()
		{
			Function();
		},
		TStatId(),	// No stat id
		nullptr,	// Do not specify a dependency
		ENamedThreads::GameThread
	);
}