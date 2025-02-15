// © 2023 CryptoAvatars. All rights reserved


#include "CryptoAvatars.h"
#include "Engine/Engine.h"
#include "ImageUtils.h"
#include "Engine/Texture2D.h"
#include "Structs/Structs.h"
#include "JsonObjectConverter.h"
#include "VRM4U/Public/VrmAssetListObject.h"
#include "Http.h"
#include "VRM4ULoader/Public/LoaderBPFunctionLibrary.h"

void UCryptoAvatars::SetApiKey(FString apiKey)
{
	const FString URL_SERVER = "https://api.cryptoavatars.io/v1/";
	const FString URL_SERVER_TEST = "http://localhost:3000/v1/";
	this->httpService = HttpService(apiKey, URL_SERVER);
}

UFUNCTION(BlueprintCallable, Category = "SDK")
void UCryptoAvatars::BPUserLogin(FString email, FString password, FOnUserLoginComplete OnComplete)
{
	UserLogin(email, password, [=](FHttpResponsePtr response) {
		if (response->GetResponseCode() == 200)
		{
			FString content = response->GetContentAsString();
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(content);
			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				FLoginResponseDto dto;
				if (FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), FLoginResponseDto::StaticStruct(), &dto))
				{
					OnComplete.Execute(dto);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("User login failed"));
		}
		});
}

void UCryptoAvatars::BPUserLoginWithMetamaskToCA(FString wallet, FString signature, FOnUserLoginComplete OnComplete)
{
	UserLoginWithMetamaskToCA(wallet, signature, [=](FHttpResponsePtr response) {
		if (response->GetResponseCode() == 200)
		{
			FString content = response->GetContentAsString();
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(content);
			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				FLoginResponseDto dto;
				if (FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), FLoginResponseDto::StaticStruct(), &dto))
				{
					OnComplete.Execute(dto);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("User login CA failed"));
		}
	});
}

void UCryptoAvatars::BPGetUserAvatars(FString owner, FString pageUrl, FOnGetAvatarsComplete OnComplete)
{
	GetUserAvatars(owner, pageUrl, [=](FHttpResponsePtr response) {
		if (response->GetResponseCode() == 200)
		{
			FString content = response->GetContentAsString();
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(content);
			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				FNftsArray dto;
				FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &dto, 0, 0);
				OnComplete.Execute(dto);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Get user avatars failed"));
		}
		});
}

void UCryptoAvatars::BPGetAvatars(FString licenseType, FString pageUrl, FOnGetAvatarsComplete OnComplete)
{
	GetAvatars(licenseType, pageUrl, [=](FHttpResponsePtr response) {
		if (response->GetResponseCode() == 200)
		{
			FString content = response->GetContentAsString();
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(content);
			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				FNftsArray dto;
				FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &dto, 0, 0);
				OnComplete.Execute(dto);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Get avatars failed"));
		}
		});
}

void UCryptoAvatars::BPGetAvatarsByName(FString licenseType, FString pageUrl, FString name, FOnGetAvatarsComplete OnComplete)
{
	GetAvatarsByName(licenseType, pageUrl, name, [=](FHttpResponsePtr response) {
		if (response->GetResponseCode() == 200)
		{
			FString content = response->GetContentAsString();
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(content);
			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				FNftsArray dto;
				FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &dto, 0, 0);
				OnComplete.Execute(dto);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Get avatars by name failed"));
		}
		});
}


void UCryptoAvatars::BPGetAvatarsByCollectionName(FString licenseType, FString pageUrl, FString collectionName, FOnGetAvatarsComplete OnComplete)
{
	GetAvatarsByCollectionName(licenseType, pageUrl, collectionName, [=](FHttpResponsePtr response) {
		if (response->GetResponseCode() == 200)
		{
			FString content = response->GetContentAsString();
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(content);
			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				FNftsArray dto;
				FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &dto, 0, 0);
				OnComplete.Execute(dto);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Get avatars by collection name failed"));
		}
		});
}

void UCryptoAvatars::BPGetUserAvatarsByCollectionName(FString owner, FString pageUrl, FString collectionName, FOnGetAvatarsComplete OnComplete)
{
	GetUserAvatarsByCollectionName(owner, pageUrl, collectionName, [=](FHttpResponsePtr response) {
		if (response->GetResponseCode() == 200)
		{
			FString content = response->GetContentAsString();
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(content);
			if (FJsonSerializer::Deserialize(Reader, JsonObject))
			{
				FNftsArray dto;
				FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &dto, 0, 0);
				OnComplete.Execute(dto);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Get user avatars by collection name failed"));
		}
		});
}

void UCryptoAvatars::BPGetAvatarPreviewImage(FString imageUrl, FOnGetAvatarPreviewComplete OnComplete)
{
}

void UCryptoAvatars::BPGetAvatarVRMModel(FString vrmUrl, FOnGetVRMComplete OnComplete)
{
	UE_LOG(LogTemp, Error, TEXT("SENDING URL: %s"), *vrmUrl);
	httpService.DownloadVRM(vrmUrl, false, [=](FString path, UVrmAssetListObject* VRM) {
		UE_LOG(LogTemp, Error, TEXT("BPGetAvatarVRMModel Path: %s"), *path);
		OnComplete.Execute(path, VRM);
		});
}

void UCryptoAvatars::BPGetNFTsCollections(FString pageUrl)
{
}

void UCryptoAvatars::UserLogin(FString email, FString password, TFunction<void(FHttpResponsePtr)> callback)
{
	FLoginRequestDto dto;
	FString resource = "login-pass";
	dto.email = email;
	dto.password = password;
	httpService.Post(resource, dto, callback);
}
void UCryptoAvatars::UserLoginWithMetamaskToCA(FString wallet, FString signature, TFunction<void(FHttpResponsePtr)> callback)
{
	FLoginMetamaskDto dto;
	FString resource = "login";
	dto.wallet = wallet;
	dto.signature = signature;
	httpService.Post(resource, dto, callback);
}
void UCryptoAvatars::GetUserAvatars(FString owner, FString pageUrl, TFunction<void(FHttpResponsePtr)> callback)
{
	FOwnerAvatarsDto dto;
	dto.owner = owner;
	httpService.Post(pageUrl, dto, callback);
}
void UCryptoAvatars::GetAvatars(FString licenseType, FString pageUrl, TFunction<void(FHttpResponsePtr)> callback)
{
	FDefaultSearchAvatarsDto dto;
	dto.license = licenseType;
	httpService.Post(pageUrl, dto, callback);
}
void UCryptoAvatars::GetAvatarsByName(FString licenseType, FString pageUrl, FString name, TFunction<void(FHttpResponsePtr)> callback)
{
	FSearchAvatarByNameDto dto;
	dto.license = licenseType;
	dto.name = name;
	httpService.Post(pageUrl, dto, callback);
}
void UCryptoAvatars::GetAvatarsByCollectionName(FString licenseType, FString pageUrl, FString collectionName, TFunction<void(FHttpResponsePtr)> callback)
{
	FDefaultSearchAvatarsDtoCollectionName dto;
	dto.collectionName = collectionName;
	httpService.Post(pageUrl, dto, callback);
}
void UCryptoAvatars::GetUserAvatarsByCollectionName(FString owner, FString pageUrl, FString collectionName, TFunction<void(FHttpResponsePtr)> callback)
{
	FOwnerAvatarsDtoCollectionName dto;
	dto.owner = owner;
	dto.collectionName = collectionName;
	httpService.Post(pageUrl, dto, callback);
}
void UCryptoAvatars::GetAvatarPreviewImage(FString imageUrl, TFunction<void (UTexture2D*)> response)
{
	imageUrl = imageUrl.Replace(TEXT("gateway.pinata.cloud"), TEXT("usercollection.mypinata.cloud"));
	DownloadImage(imageUrl, response);
}

void UCryptoAvatars::GetAvatarVRMModel(FString vrmUrl, TFunction<void(UVrmAssetListObject*)> response)
{
	vrmUrl = vrmUrl.Replace(TEXT("gateway.pinata.cloud"), TEXT("usercollection.mypinata.cloud"));
	UE_LOG(LogTemp, Warning, TEXT("URL AFTER THE CHANGE: %s"), *vrmUrl);
	httpService.DownloadVRM(vrmUrl, false, [=](FString path, UVrmAssetListObject* VRM) {
		// Use the path to load the VRM model
		UVrmAssetListObject* vrmAsset;
		FImportOptionData OptionForRuntimeLoad;
		FLatentActionInfo LatentInfo;
	ULoaderBPFunctionLibrary::LoadVRMFileAsync(this, VRM, vrmAsset, path, OptionForRuntimeLoad, LatentInfo);
		response(vrmAsset);
		});
}

void UCryptoAvatars::ImportVRMFromFile(FString filePath)
{
	// Import the VRM model
	UVrmAssetListObject* vrmAsset = NewObject<UVrmAssetListObject>();
	FImportOptionData OptionForRuntimeLoad;
	OptionForRuntimeLoad.StaticStruct();
	FLatentActionInfo LatentInfo;
	LatentInfo.StaticStruct();
	ULoaderBPFunctionLibrary::LoadVRMFileAsync(this, vrmAsset, vrmAsset, filePath, OptionForRuntimeLoad, LatentInfo);
}

void UCryptoAvatars::DownloadImage(FString url, TFunction<void(UTexture2D*)> callback)
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->SetURL(url);
	Request->SetVerb("GET");
	Request->OnProcessRequestComplete().BindLambda
	([callback](FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) {
		if (bWasSuccessful && response.IsValid() && response->GetContent().Num() > 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Response Content Type: %s"), *FString(response->GetHeader("Content-Type")));
			UTexture2D* AvatarTexture = FImageUtils::ImportBufferAsTexture2D(response->GetContent());
			UE_LOG(LogTemp, Warning, TEXT("AvatarTexture Width: %d, Height: %d"), AvatarTexture->GetSizeX(), AvatarTexture->GetSizeY());
			callback(AvatarTexture);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Response Failed: %s"), response->GetResponseCode());
			callback(nullptr);
		}
		});
	Request->ProcessRequest();
}

