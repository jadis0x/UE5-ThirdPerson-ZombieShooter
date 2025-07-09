// Jadis0x - All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


class AWeapon;
class ACharacterBase;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DECAYPROTOCOL_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCombatComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	friend ACharacterBase;

	void EquipWeapon(AWeapon* Weapon);
protected:
	virtual void BeginPlay() override;

private:
	ACharacterBase* Character;
	AWeapon* EquippedWeapon;
};
