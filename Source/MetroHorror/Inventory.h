#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item.h"
#include "Inventory.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class METROHORROR_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<UItem*> Items;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	UItem* ActiveItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	ACharacter* PlayerBP;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(UItem* itemToAdd);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(int32 itemIndex);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void CheckInventory();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SelectItem(int32 itemIndex);
};