// Jadis0x - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PickupWidget.generated.h"

class UTextBlock;
class UBorder;

UCLASS()
class DECAYPROTOCOL_API UPickupWidget : public UUserWidget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* PickupText;

	UPROPERTY(meta = (BindWidget))
	UBorder* PickupBorder;
};
