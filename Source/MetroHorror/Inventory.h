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

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(UItem* itemToAdd);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(UItem* itemToRemove);
};