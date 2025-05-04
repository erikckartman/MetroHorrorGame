#include "Inventory.h"

void UInventory::AddItem(UItem* itemToAdd) {
	if (itemToAdd) {
		Items.Add(itemToAdd);
	}
}

void UInventory::RemoveItem(UItem* itemToRemove) {
	if (Items.Contains(itemToRemove)) {
		Items.Remove(itemToRemove);
	}
}