// Fill out your copyright notice in the Description page of Project Settings.


#include "AUMG.h"

// Sets default values
AAUMG::AAUMG()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	MainWidgetInstance = nullptr;
	//static ConstructorHelpers::FClassFinder<UUserWidget> WidgetBPClass(TEXT("/Game/BluePrints/BP_UI.BP_UI_C'"));
	//if (WidgetBPClass.Succeeded())
	//{
	//	MainWidgetClass = WidgetBPClass.Class;
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (FString::FromInt(222)));
	//}
	//else
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (FString::FromInt(111)));
	//}
}

// Called when the game starts or when spawned
void AAUMG::BeginPlay()
{
	Super::BeginPlay();
	UClass* CustomWidgetClass = LoadClass<UUserWidget>(nullptr, TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrints/BP_UI.BP_UI_C'"));
	if (IsValid(CustomWidgetClass))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (FString::FromInt(222)));
		if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
		{
			MainWidgetInstance = CreateWidget(PC, CustomWidgetClass);
			if (IsValid(MainWidgetInstance))
			{
				MainWidgetInstance->AddToViewport();
			}
		}
	}
	//XDebugMenu = CreateWidget<UUI_Widget>(GetWorld(), DebugMenuWdgClass);
	//if (IsValid(XDebugMenu))
	//{
	//	XDebugMenu->AddToViewport();
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (FString::FromInt(222)));
	//}
	//else
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (FString::FromInt(111)));
	//}
	//UUI_Widget::NativeConstruct();
}

// Called every frame
void AAUMG::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

