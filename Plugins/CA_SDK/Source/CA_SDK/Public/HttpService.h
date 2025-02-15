// © 2023 CryptoAvatars. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include <VrmAssetListObject.h>
/**
 * 
 */
class IHttpRequest;
class IHttpResponse;

typedef TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> FHttpRequestPtr;
typedef TSharedPtr<IHttpResponse, ESPMode::ThreadSafe> FHttpResponsePtr;

typedef TSharedRef<IHttpRequest, ESPMode::ThreadSafe> FHttpRequestRef;
typedef TSharedRef<IHttpResponse, ESPMode::ThreadSafe> FHttpResponseRef;

class CA_SDK_API HttpService
{
public:
	HttpService();
	~HttpService() = default;
	HttpService(FString apiKey, FString baseUri);
	// Base Request
	void HttpMethod(FHttpRequestRef request, TFunction<void(FHttpResponsePtr)> callback);
	template<typename T>
	void Post(FString endpoint, T body, TFunction<void(FHttpResponsePtr)> callback);
	void Get(FString endpoint, TFunction<void(FHttpResponsePtr)> callback);
	void DownloadImage(FString url, FHttpResponsePtr responseDelegate);
	void DownloadVRM(FString url,bool isEncrypted, TFunction<void(FString, UVrmAssetListObject*)> callback);
private:
	FString apiKey;
	FString baseUri;
	TArray<uint8> DecryptVRM(TArray<uint8> data);
};


