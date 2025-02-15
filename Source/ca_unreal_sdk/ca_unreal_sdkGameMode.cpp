// Copyright Epic Games, Inc. All Rights Reserved.

#include "ca_unreal_sdkGameMode.h"
#include "ca_unreal_sdkCharacter.h"
#include "Json.h"
#include "CA_SDK/Public/Structs/Structs.h"
#include "CA_SDK/Public/CryptoAvatars.h"
#include "JsonObjectConverter.h"
#include "Components/Image.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Slate.h"
Aca_unreal_sdkGameMode::Aca_unreal_sdkGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void Aca_unreal_sdkGameMode::StartPlay() {
	Super::StartPlay();
	// Create Widget
	//if (WidgetTemplate)
	//{
		//UE_LOG(LogTemp, Warning, TEXT("Widget Template is not null"));
		if (!WidgetInstance)
		{
			//WidgetInstance = Cast<UAvatarCardPreview>(CreateWidget(UGameplayStatics::GetPlayerController(this, 0), WidgetTemplate));
			WidgetInstance = Cast<UAvatarCardPreview>(CreateWidget<UAvatarCardPreview>(GetWorld(), UAvatarCardPreview::StaticClass()));
			
			WidgetInstance->AddToViewport();
			//WidgetInstance->RemoveFromViewport();
			UE_LOG(LogTemp, Warning, TEXT("Widget Instance created"));
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("Widget Instance had a previous value"));
		}
	//}
	/*else {
		UE_LOG(LogTemp, Error, TEXT("Widget Template is null"));
	}*/

	
	PostRequestExample();
	//GetRequestExample();
}

void Aca_unreal_sdkGameMode::GetRequestExample()
{
	FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &Aca_unreal_sdkGameMode::OnResponseReceived);
	Request->SetURL("https://api.cryptoavatars.io/v1/collections/total");
	Request->SetHeader("API-KEY", "$2b$10$Yaenvbe2pRfadxqZT0vOHet50SX6NEbdSQ5lrqV.M7on2hRKkCC/6");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}
void Aca_unreal_sdkGameMode::PostRequestExample() {
	//#pragma region Body Part
	//FString RequestBody = "{}";
	//TSharedRef<FJsonObject> RequestObj = MakeShared<FJsonObject>();
	//TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&RequestBody);
	//FJsonSerializer::Serialize(RequestObj, Writer);
	//#pragma endregion Body Part
	//FHttpRequestRef Request = FHttpModule::Get().CreateRequest();
	//// We can parametrize OnResponseReceived delegate
	//Request->OnProcessRequestComplete().BindUObject(this, &Aca_unreal_sdkGameMode::OnResponseReceived);
	//// Parametrize part of the URL
	//Request->SetURL("https://api.cryptoavatars.io/v1/nfts/avatars/list?skip=0&limit=20");
	//// This will always be the same
	//Request->SetVerb("POST");
	//Request->SetHeader("Content-Type", "application/json");
	//// Parametrize the API-KEY Value
	//Request->SetHeader("API-KEY", "$2b$10$Yaenvbe2pRfadxqZT0vOHet50SX6NEbdSQ5lrqV.M7on2hRKkCC/6");
	//Request->SetContentAsString(RequestBody);
	//Request->ProcessRequest();

	//UCryptoAvatars cryptoAvatars("$2b$10$Yaenvbe2pRfadxqZT0vOHet50SX6NEbdSQ5lrqV.M7on2hRKkCC/6");
	FString licenseType = "CC0";
	FString pageUrl = "nfts/avatars/list?skip=0&limit=20";
	FString avatarName = "Banana";
	FString collectionName = "The User Collection";
	FString userWallet = "0x242A5a3f94b2Fdd52Da2cb923214f4C2426a865B";
	FString testEmail = "erik.mateos@cryptoavatars.io";
	FString testPassword = "lolxdx";
	FString imageURL = "https://usercollection.mypinata.cloud/ipfs/QmVadEnWEXZYRP8VpzUDrpyK6vHv7omWLMvnbdRC6pt9nZ/CV%20Jin_Thumbnail.png";
	//cryptoAvatars.GetAvatars(licenseType, pageUrl, response);
	// You can add a callback function to do something with the response 
	
	//FStringClassReference MyWidgetClassRef(TEXT("/Plugins/CA_SDK/Content/Widgets/AvatarCardImage.AvatarCardImage_C"));
	//UUserWidget* ImageWidget = nullptr;
	//if (UClass* ImageWidget = MyWidgetClassRef.TryLoadClass<UUserWidget>())
	//{
	//	ImageWidget = CreateWidget<UUserWidget>(this->GetWorld(), MyWidgetClassRef);
	//	// Do stuff with MyWidget
	//}
	//UImage* Image = Cast<UImage>(ImageWidget->GetWidgetFromName(FName("YourImageName")));
	//if (Image)
	//{
	//	// Set the texture of the Image
	//	Image->SetBrushFromTexture(response);
	//}
	//// Add the widget to the viewport
	//ImageWidget->AddToViewport();
//	cryptoAvatars.GetAvatarPreviewImage(imageURL, [this](UTexture2D* response) {
//		if (response)
//		{
//			UE_LOG(LogTemp, Warning, TEXT("AvatarTexture Width: %d, Height: %d"), response->GetSizeX(), response->GetSizeY());
//			// Get the Image component
//			UImage* img = NewObject<UImage>(UImage::StaticClass());
//			img->SetVisibility(ESlateVisibility::Visible);
//			UTexture2DDynamic* yourTexture = UTexture2DDynamic::Create(response->GetSizeX(), response->GetSizeY());
//			yourTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
//			yourTexture->LODGroup = TextureGroup::TEXTUREGROUP_UI;
//			yourTexture->UpdateResource();
//			//WidgetInstance->SetAvatarImage(yourTexture);
//			if (img)
//			{
//				// Set the brush of the Image component to the UTexture2D
//				img->SetBrushFromTexture(response);
//			}
//			// Add the widget to the viewport
//			WidgetInstance->AddToViewport();
//		}
//		else
//		{
//			UE_LOG(LogTemp, Error, TEXT("Error loading image"));
//		}
//		});
}
	
void Aca_unreal_sdkGameMode::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	//TSharedPtr<FJsonObject> ResponseObj;
	//TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	//FJsonSerializer::Deserialize(Reader, ResponseObj);
	//FNftsArray nfts;
	//UE_LOG(LogTemp, Display, TEXT("Response %s"), *Response->GetContentAsString());
	//TArray<TSharedPtr<FJsonValue>> JsonParsed;
	//const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(*Response->GetContentAsString());
	//
	//TArray<TSharedPtr<FJsonValue>> nftsArray = ResponseObj->GetArrayField("nfts");
	//
	//for (int i = 0; i < nftsArray.Num(); i++) {
	//	FNft nft;
	//	FJsonObjectConverter::JsonObjectToUStruct(nftsArray[i]->AsObject().ToSharedRef(), &nft, 0, 0);
	//	nfts.nfts.Add(nft);
	//	UE_LOG(LogTemp, Display, TEXT("Response %s"), *nft.metadata.name);
	//}
	
	/*for (int32 i = 0; i < nftsArray.Num(); ++i) {
		nfts.nfts[i] = nftsArray[i];
	}*/
	//FJsonObjectConverter::JsonObjectStringToUStruct(*Response->GetContentAsString(), &nfts, 0, 0);
	
	//UE_LOG(LogTemp, Display, TEXT("Response %s"), "PARSING SUCCESS");
	////UE_LOG(LogTemp, Display, TEXT("Respones %s", n))
	//for(auto nft : nftsArray)
	//{
	//	UE_LOG(LogTemp, Display, TEXT("Response %s"), *nft->AsString());
	//}
	
	//UE_LOG(LogTemp, Display, TEXT("Response %s"), bConnectedSuccessfully);
	//UE_LOG(LogTemp, Display, TEXT("Name %s"), *ResponseObj->GetIntegerField("name"));
}
template <typename T>
void Aca_unreal_sdkGameMode::GetData(FString& data, T& dataStruct) {
	FJsonObjectConverter::JsonObjectStringToUStruct(data, &dataStruct,0,0);
}
