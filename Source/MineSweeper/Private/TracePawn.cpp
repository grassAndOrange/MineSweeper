// Fill out your copyright notice in the Description page of Project Settings.


#include "TracePawn.h"
#include "UI_Widget.h"

// Sets default values
ATracePawn::ATracePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FClassFinder<UUserWidget> WidgetBPClass(TEXT("/Game/BluePrints/BP_UI.BP_UI_C"));
	//if (WidgetBPClass.Succeeded())
	//{
	//	UIWidgetClass = WidgetBPClass.Class;
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (FString::FromInt(222)));
	//}
	//else
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (FString::FromInt(111)));
	//}
}

// Called when the game starts or when spawned
void ATracePawn::BeginPlay()
{
	Super::BeginPlay();
	
	//if (UIWidgetClass)
	//{
	//	UIWidgetInstance = CreateWidget<UUserWidget>(this, UIWidgetClass);
	//	if (UIWidgetInstance)
	//	{
	//		// 显示UI
	//		UIWidgetInstance->AddToViewport();
	//	}
	//}
}

// Called every frame
void ATracePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APlayerController* controller = Cast<APlayerController>(GetController());
	if (controller)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,TEXT("H"));
		FVector Start, Dir, End;
		controller->DeprojectMousePositionToWorld(Start,Dir);
		End = Start + Dir * 10000;
		Trace(Start, End);
	}

}

// Called to bind functionality to input
void ATracePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Mouse_R", IE_Pressed, this, &ATracePawn::Click_R);
}

void ATracePawn::Trace(FVector Start, FVector End)
{
	FHitResult HitResult;
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility);
	if (bHit)
    {
		if (IsValid(HitResult.GetActor()))
		{
			AMineBasic* HitActor = Cast<AMineBasic>(HitResult.GetActor());
			if (IsValid(HitActor))
			{
				FocuseCube = HitActor;

				now = *HitResult.GetActor()->GetName();
				if (now != before)
				{
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Hit Actor: %s"), *HitResult.GetActor()->GetName()));
				}
				before = now;
			}
		}
    }
	else
	{
		FocuseCube = nullptr;
	}
}

void ATracePawn::Click_R()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("123")));
    if (IsValid(FocuseCube)&&(!FocuseCube->isFlag)&&(FocuseCube->cubeMesh->IsVisible()))
    {
		FocuseCube->numText->SetVisibility(false);
		FocuseCube->flagMesh->SetVisibility(true);
		FocuseCube->isFlag = true;
    }
	else if(IsValid(FocuseCube) && (FocuseCube->isFlag) && (FocuseCube->cubeMesh->IsVisible()))
	{
		FocuseCube->numText->SetVisibility(true);
		FocuseCube->flagMesh->SetVisibility(false);
		FocuseCube->isFlag = false;
	}
}

