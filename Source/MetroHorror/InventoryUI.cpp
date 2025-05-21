#include "InventoryUI.h"
#include "Inventory.h"
#include "Components/Button.h"

void UInventoryUI::UpdateIcons() {
	if (!InventoryRef) return;

	for (int i = 0; i < Slots.Num(); i++) {
		if (!Slots[i]) continue;

		UTexture2D* IconToSet = DefaultIcon;

		if (InventoryRef->Items.IsValidIndex(i) && InventoryRef->Items[i]) {
			IconToSet = InventoryRef->Items[i]->ItemIcon;
		}

		FButtonStyle NewStyle = Slots[i]->WidgetStyle;

		FSlateBrush BaseBrush;
		BaseBrush.SetResourceObject(IconToSet);
		BaseBrush.ImageSize = FVector2D(64.f, 64.f);

		FSlateBrush NormalBrush = BaseBrush;
		FSlateBrush HoveredBrush = BaseBrush;
		FSlateBrush PressedBrush = BaseBrush;

		NormalBrush.TintColor = FLinearColor(1.f, 1.f, 1.f, 1.f);
		HoveredBrush.TintColor = FLinearColor(0.7f, 0.7f, 0.7f, 1.f);
		PressedBrush.TintColor = FLinearColor(0.5f, 0.5f, 0.5f, 1.f);

		NewStyle.Normal = NormalBrush;
		NewStyle.Hovered = HoveredBrush;
		NewStyle.Pressed = PressedBrush;

		Slots[i]->SetStyle(NewStyle);
	}
}