#include "InventoryUI.h" 
#include "Components/Image.h"

void UInventoryUI::NativeConstruct() {
	
	Super::NativeConstruct();

	ImageWidgets = { Image_0, Image_1, Image_2, Image_3 };
}

void UInventoryUI::UpdateIcons(const TArray<UItem*> Items) { 
	for (int32 i = 0; i < ImageWidgets.Num(); ++i) { 
		if (ImageWidgets[i]) { 
			if (Items.IsValidIndex(i) && Items[i]->ItemIcon) { 
				ImageWidgets[i]->SetBrushFromTexture(Items[i]->ItemIcon); 
			} 
			else { 
				ImageWidgets[i]->SetBrushFromTexture(DefaultIcon); 
			} 
		} 
	} 
}
