#include "Inventory.h"

void UInventory::AddItem(UItem* itemToAdd) {
	if (itemToAdd) {
		Items.Add(itemToAdd);
		UE_LOG(LogTemp, Warning, TEXT("Item succesfully added"));
	}
}

void UInventory::RemoveItem(UItem* itemToRemove) {
	if (Items.Contains(itemToRemove)) {
		Items.Remove(itemToRemove);
	}
}

void UInventory::CheckInventory() {
	for (UItem* oneItem : Items)
	{
		UE_LOG(LogTemp, Log, TEXT("Item: %s"), *oneItem->ItemName.ToString());
	}
}