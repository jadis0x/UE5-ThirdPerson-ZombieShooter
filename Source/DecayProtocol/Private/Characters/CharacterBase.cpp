// Jadis0x - All Rights Reserved


#include "Characters/CharacterBase.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "Widgets/Misc/NetRoleWidget.h"


ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 170.f;
	CameraBoom->SetRelativeLocation(FVector(0.f, 0.f, 120.f));
	CameraBoom->SocketOffset = FVector(0.f, 45.f, 30.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	NetRoleWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("NetRoleWidget"));
	NetRoleWidget->SetupAttachment(GetRootComponent());
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	if(NetRoleWidget)
	{
		if(UNetRoleWidget* NetRole = Cast<UNetRoleWidget>(NetRoleWidget->GetUserWidgetObject()))
		{
			NetRole->ShowPlayerNetRole(this);
		}
	}
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ThisClass::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ThisClass::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ThisClass::Turn);
	PlayerInputComponent->BindAxis("Look", this, &ThisClass::Look);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
}

void ACharacterBase::MoveForward(float Value)
{
	if(Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));

		AddMovementInput(Direction, Value);
	}
}

void ACharacterBase::MoveRight(float Value)
{
	if(Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));

		AddMovementInput(Direction, Value);
	}
}


void ACharacterBase::Turn(float Value)
{
	AddControllerYawInput(Value);
}


void ACharacterBase::Look(float Value)
{
	AddControllerPitchInput(Value);
}

