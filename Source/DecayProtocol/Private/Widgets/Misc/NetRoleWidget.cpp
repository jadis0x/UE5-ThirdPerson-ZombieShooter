// Jadis0x - All Rights Reserved


#include "Widgets/Misc/NetRoleWidget.h"
#include "Components/TextBlock.h"

void UNetRoleWidget::SetDisplayText(FString TextToDisplay)
{
	if(DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UNetRoleWidget::ShowPlayerNetRole(APawn* InPawn)
{
	if(!InPawn)
	{
		SetDisplayText(TEXT("Remote Role: INVALID (null pawn)"));
		return;
	}

	const ENetRole RemoteRole = InPawn->GetRemoteRole();
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("ENetRole"), true);

	FString RoleString = EnumPtr
		? EnumPtr->GetNameStringByValue((int64)RemoteRole)
		: TEXT("Unknown");

	SetDisplayText(FString::Printf(TEXT("%s"), *RoleString));
}

void UNetRoleWidget::NativeDestruct()
{
	RemoveFromParent();

	Super::NativeDestruct();
}
