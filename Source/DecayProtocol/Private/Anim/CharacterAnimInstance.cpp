// Jadis0x - All Rights Reserved


#include "Anim/CharacterAnimInstance.h"

#include "Characters/CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	CharacterBase = Cast<ACharacterBase>(TryGetPawnOwner());
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if(CharacterBase == nullptr)
	{
		CharacterBase = Cast<ACharacterBase>(TryGetPawnOwner());
	}

	if(CharacterBase == nullptr) return;

	FVector Velocity = CharacterBase->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	bIsInAir = CharacterBase->GetCharacterMovement()->IsFalling();
	bIsAccelerating = CharacterBase->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
}
