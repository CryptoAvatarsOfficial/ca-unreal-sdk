// © 2023 CryptoAvatars. All rights reserved

#include "HttpService.h"
#include "JsonObjectConverter.h"
#include "Http.h"
#include "Structs/Structs.h"
#include <VrmAssetListObject.h>
#include <VRM4UImporter/Private/VRM4UImporterFactory.h>
#include <VrmRuntimeSettings.h>
#include <LoaderBPFunctionLibrary.h>
#pragma region Avatars Post
template void HttpService::Post(FString endpoint, struct FDefaultSearchAvatarsDto body, TFunction<void(FHttpResponsePtr)> callback);
template void HttpService::Post(FString endpoint, struct FSearchAvatarByNameDto body, TFunction<void(FHttpResponsePtr)> callback);
template void HttpService::Post(FString endpoint, struct FDefaultSearchAvatarsDtoCollectionName body, TFunction<void(FHttpResponsePtr)> callback);
template void HttpService::Post(FString endpoint, struct FOwnerAvatarsDto body, TFunction<void(FHttpResponsePtr)> callback);
template void HttpService::Post(FString endpoint, struct FOwnerAvatarsDtoCollectionName body, TFunction<void(FHttpResponsePtr)> callback);
#pragma endregion Avatars Post Template Explicit Instantiation

#pragma region Login
template void HttpService::Post(FString endpoint, struct FLoginRequestDto body, TFunction<void(FHttpResponsePtr)> callback);
template void HttpService::Post(FString endpoint, struct FLoginMetamaskDto body, TFunction<void(FHttpResponsePtr)> callback);
#pragma endregion Login Post Template Explicit Instantiation

HttpService::HttpService() {
	this->apiKey = "";
	this->baseUri = "";
}

HttpService::HttpService(FString apiKey, FString baseUri)
{
	this->apiKey = apiKey;
	this->baseUri = baseUri;
}

void HttpService::HttpMethod(FHttpRequestRef request, TFunction<void(FHttpResponsePtr)> callback)
{
	request->SetHeader("API-KEY", this->apiKey);
	request->SetHeader("Content-Type", "application/json");
	request->OnProcessRequestComplete().BindLambda
	([callback](FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) {
		if (bWasSuccessful)
		{
			UE_LOG(LogTemp, Warning, TEXT("Got Response: %s"), *response->GetContentAsString());
			callback(response);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Response Failed: %d"), response->GetResponseCode());
			callback(response);
		}
		});
	request->ProcessRequest();
}
//
// ESTO PETA IDK
void HttpService::Get(FString endpoint, TFunction<void(FHttpResponsePtr)> callback)
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	//Request->OnProcessRequestComplete().BindUObject(this, &Aca_unreal_sdkGameMode::OnResponseReceived);
	Request->SetURL(this->baseUri + endpoint);
	Request->SetVerb("GET");
	HttpMethod(Request, callback);
}

template<typename T>
void HttpService::Post(FString endpoint, T body, TFunction<void(FHttpResponsePtr)> callback)
{
	FString bodyJson;
	FJsonObjectConverter::UStructToJsonObjectString(body, bodyJson,0,0);
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	UE_LOG(LogTemp, Warning, TEXT("URI SENT: %s"), *FString(this->baseUri + endpoint));
	Request->SetURL(this->baseUri + endpoint);
	Request->SetVerb("POST");
	Request->SetContentAsString(bodyJson);
	HttpMethod(Request, callback);
}

void HttpService::DownloadVRM(FString url, bool isEncrypted, TFunction<void(FString, UVrmAssetListObject*)> callback) {
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request{ FHttpModule::Get().CreateRequest() };
	url = url.Replace(TEXT("gateway.pinata.cloud"), TEXT("usercollection.mypinata.cloud"));
	request->SetURL(url);
	UE_LOG(LogTemp, Warning, TEXT("URL AFTER THE CHANGE: %s"), *url);
	request->SetVerb("GET");
	request->SetTimeout(5000);
	request->OnProcessRequestComplete().BindLambda([isEncrypted, callback]
	(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) {
			if (!bWasSuccessful || !response.IsValid() || response->GetResponseCode() != 200)
			{
				UE_LOG(LogTemp, Error, TEXT("Error requesting to %s"),
					*request->GetURL());
				return;
			}
			else
			{
				TArray<uint8> results = response->GetContent();
				if (isEncrypted)
				{
					// Add decryption logic here
				}

				FString dirPath = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("cryptoavatars"));
				if (!FPaths::DirectoryExists(dirPath))
					FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*dirPath);

				FString path = FPaths::Combine(dirPath, TEXT("avatarDownloaded.vrm"));
				FFileHelper::SaveArrayToFile(results, *path);
				// VRM Import here
				UVrmAssetListObject* vrmAsset = NewObject<UVrmAssetListObject>();
				callback(path, Cast<UVrmAssetListObject>(vrmAsset));
			}
		});
	request->ProcessRequest();
}

TArray<uint8> HttpService::DecryptVRM(TArray<uint8> data) {
	TArray<uint8> result;
	return result;
}