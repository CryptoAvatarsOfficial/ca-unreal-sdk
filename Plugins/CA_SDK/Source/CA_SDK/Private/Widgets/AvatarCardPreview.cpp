// © 2023 CryptoAvatars. All rights reserved


#include "Widgets/AvatarCardPreview.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
void UAvatarCardPreview::NativeConstruct()
{
	Super::NativeConstruct();
    if (TitleLabel)
    {
        TitleLabel->SetText(FText::FromString(TEXT("Hello world!")));
    }
    UImage* Image = NewObject<UImage>(this);
    UPanelWidget* Panel = Cast<UPanelWidget>(GetRootWidget());
    if (Panel)
    {
        Panel->AddChild(Image);
        AvatarPreviewImage = Image;
    }
    if (AvatarPreviewImage) {
        UE_LOG(LogTemp, Warning, TEXT("AvatarPreviewImage created"));
    }
}
