// Jadis0x - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NetRoleWidget.generated.h"

class UTextBlock;

UCLASS()
class DECAYPROTOCOL_API UNetRoleWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(APawn* InPawn);

private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* DisplayText;

	void SetDisplayText(FString TextToDisplay);
protected:
	virtual void NativeDestruct() override;
};
