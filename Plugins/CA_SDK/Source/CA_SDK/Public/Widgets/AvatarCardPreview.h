// © 2023 CryptoAvatars. All rights reserved

#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/Image.h>
#include "AvatarCardPreview.generated.h"
/**
 * 
 */
UCLASS()
class CA_SDK_API UAvatarCardPreview : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (BindWidget))
	UImage* AvatarPreviewImage;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* TitleLabel;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UImage* IconImage;
};
