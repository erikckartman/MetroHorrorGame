#pragma once

#include "CoreMinimal.h" 
#include "Blueprint/UserWidget.h" 
#include "Components/Image.h" 
#include "Item.h"
#include "InventoryUI.generated.h"

class UImage;

UCLASS() class METROHORROR_API UInventoryUI : public UUserWidget {
	
	GENERATED_BODY()

protected: virtual void NativeConstruct() override;

public: void UpdateIcons(const TArray<UItem*> Items);

	  UPROPERTY(meta = (BindWidget))
	  UImage* Image_0;

	  UPROPERTY(meta = (BindWidget))
	  UImage* Image_1;

	  UPROPERTY(meta = (BindWidget))
	  UImage* Image_2;

	  UPROPERTY(meta = (BindWidget))
	  UImage* Image_3;

	  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	  UTexture2D* DefaultIcon;

	private: TArray<UImage*> ImageWidgets;
};

