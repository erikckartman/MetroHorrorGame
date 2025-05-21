#include "Inventory.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Item.h"

void UInventory::AddItem(UItem* itemToAdd) {
	if (itemToAdd) {
		Items.Add(itemToAdd);
		UE_LOG(LogTemp, Warning, TEXT("Item succesfully added"));
	}
}

void UInventory::RemoveItem(int32 itemIndex) {
	UItem* ItemToDrop = Items[itemIndex];
	
	if (!ItemToDrop || !ItemToDrop->ItemMesh) return;
	
	FVector PlayerLocation = PlayerBP->GetActorLocation();
	FRotator PlayerRotation = PlayerBP->GetActorRotation();

	FVector ForwardVector = PlayerBP->GetActorForwardVector();
	FVector SpawnLocation = PlayerLocation + ForwardVector * 100.f;

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AActor* DroppedActor = PlayerBP->GetWorld()->SpawnActor<AActor>(
		ItemToDrop->ItemMesh,
		SpawnLocation,
		PlayerRotation,
		SpawnParams
	);

	if (DroppedActor) {
		UE_LOG(LogTemp, Warning, TEXT("Dropped item: %s"), *ItemToDrop->ItemName.ToString());
		Items.RemoveAt(itemIndex);
	}
}

void UInventory::CheckInventory() {
	for (UItem* oneItem : Items)
	{
		UE_LOG(LogTemp, Log, TEXT("Item: %s"), *oneItem->ItemName.ToString());
	}
}

void UInventory::SelectItem(int32 itemIndex) {
	ActiveItem = Items[itemIndex];
}