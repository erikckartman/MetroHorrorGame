#include "InventoryUI.h"
#include "Inventory.h"
#include "Components/Image.h"

void UInventoryUI::UpdateIcons() {
	if (!InventoryRef) return;

	for (int i = 0; i < Slots.Num(); i++) {
		if (InventoryRef->Items.IsValidIndex(i) && InventoryRef->Items[i]) {
			Slots[i]->SetBrushFromTexture(InventoryRef->Items[i]->ItemIcon);
		}
		else {
			Slots[i]->SetBrushFromTexture(DefaultIcon);
		}
	}
}