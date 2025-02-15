// © 2023 CryptoAvatars. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Json.h"
#include "Structs/Structs.h"
#include "HttpService.h"
#include "GameFramework/Pawn.h"
#include "CryptoAvatars.generated.h"

// class FHttpResponsePtr;
// class HttpService;
/**
 * CryptoAvatars Core Functions
 */

UCLASS(BlueprintType)
class CA_SDK_API UCryptoAvatars : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()
public:
	DECLARE_DYNAMIC_DELEGATE_OneParam(FOnUserLoginComplete, FLoginResponseDto, ResponseDTO);
	DECLARE_DYNAMIC_DELEGATE_OneParam(FOnGetAvatarsComplete, FNftsArray, Avatars);
	DECLARE_DYNAMIC_DELEGATE_OneParam(FOnGetAvatarPreviewComplete, UTexture2D*, AvatarImage);
	DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnGetVRMComplete, FString, VRMPath, UVrmAssetListObject*,VRM);
	UCryptoAvatars() = default;
	~UCryptoAvatars() = default;
#pragma region BlueprintCallables
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void SetApiKey(FString apiKey);
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void BPUserLogin(FString email, FString password, FOnUserLoginComplete OnComplete);
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void BPUserLoginWithMetamaskToCA(FString wallet, FString signature, FOnUserLoginComplete OnComplete);
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void BPGetUserAvatars(FString owner, FString pageUrl, FOnGetAvatarsComplete OnComplete);
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void BPGetAvatars(FString licenseType, FString pageUrl, FOnGetAvatarsComplete OnComplete);
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void BPGetAvatarsByName(FString licenseType, FString pageUrl, FString name, FOnGetAvatarsComplete OnComplete);
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void BPGetAvatarsByCollectionName(FString licenseType, FString pageUrl, FString collectionName, FOnGetAvatarsComplete OnComplete);
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void BPGetUserAvatarsByCollectionName(FString owner, FString pageUrl, FString collectionName, FOnGetAvatarsComplete OnComplete);
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void BPGetAvatarPreviewImage(FString imageUrl, FOnGetAvatarPreviewComplete OnComplete);
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void BPGetAvatarVRMModel(FString vrmUrl, FOnGetVRMComplete OnComplete);
	UFUNCTION(BlueprintCallable, Category = "SDK")
	void BPGetNFTsCollections(FString pageUrl);
#pragma endregion BlueprintCallables
#pragma region C++ TFunctions
	// C++ only
	void UserLogin(FString email, FString password, TFunction<void(FHttpResponsePtr)> callback);
	void UserLoginWithMetamaskToCA(FString wallet, FString signature, TFunction<void(FHttpResponsePtr)> callback);
	void GetUserAvatars(FString owner, FString pageUrl, TFunction<void(FHttpResponsePtr)> callback);
	void GetAvatars(FString licenseType, FString pageUrl, TFunction<void(FHttpResponsePtr)> callback);
	void GetAvatarsByName(FString licenseType, FString pageUrl, FString name, TFunction<void(FHttpResponsePtr)> callback);
	void GetAvatarsByCollectionName(FString licenseType, FString pageUrl,FString collectionName, TFunction<void(FHttpResponsePtr)> callback);
	void GetUserAvatarsByCollectionName(FString owner, FString pageUrl, FString collectionName, TFunction<void(FHttpResponsePtr)> callback);
	/**
	 * Convert bytes to texture. This is fully engine-based functionality and may not be well optimized
	 *
	 * @param Bytes Byte array to convert to texture
	 * @return Converted texture or nullptr on failure
	 */
	void GetAvatarPreviewImage(FString imageUrl, TFunction<void(UTexture2D*)> response);
	void GetAvatarVRMModel(FString vrmUrl, TFunction<void(class UVrmAssetListObject*)> response);
	void GetNFTsCollections(FString pageUrl, TFunction<void(FHttpResponsePtr)> response);
	void ImportVRMFromFile(FString filePath);
#pragma endregion C++TFunctions
protected:
	HttpService httpService;
	void DownloadImage(FString url, TFunction<void(UTexture2D*)> response);
	/**
	 * Broadcast the progress both multi-cast and single-cast delegates
	 * @note To get the download percentage, divide the BytesReceived value by the ContentLength
	 */
	void BroadcastProgress(const int32 BytesReceived, const int32 ContentLength) const;
	// UVrmAssetListObject* ImportVRMModel(FString path, TFunction<void(UVrmAssetListObject*)> response);
	
};
