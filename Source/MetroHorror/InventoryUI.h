#pragma once

#include "CoreMinimal.h" 
#include "Blueprint/UserWidget.h" 
#include "Components/Button.h"
#include "Item.h"
#include "InventoryUI.generated.h"

class UButton;
class UInventory;

UCLASS()
class METROHORROR_API UInventoryUI : public UUserWidget {
	
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (ExposeOnSpawn = true), Category = "Inventory")
	UInventory* InventoryRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetOptional))
	TArray<UButton*> Slots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UTexture2D* DefaultIcon;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UpdateIcons();
};