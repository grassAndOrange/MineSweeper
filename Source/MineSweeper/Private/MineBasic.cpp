// Fill out your copyright notice in the Description page of Project Settings.


#include "MineBasic.h"

// Sets default values
AMineBasic::AMineBasic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	cubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	flagMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FlagMesh"));
	bombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bombMesh"));
	numText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("numText"));

	cubeMesh->SetupAttachment(RootComponent);
	flagMesh->SetupAttachment(RootComponent);
	bombMesh->SetupAttachment(RootComponent);
	numText->SetupAttachment(RootComponent);

	flagMesh->SetRelativeLocation(FVector(0, 8, 25));
	flagMesh->SetRelativeRotation(FRotator(90, 0, 180));
	flagMesh->SetRelativeScale3D(FVector(0.4, 0.4, 0.4));
	flagMesh->SetVisibility(false);

	bombMesh->SetRelativeScale3D(FVector(0.15, 0.15, 0.15));
	bombMesh->SetVisibility(false);

    numText->SetRelativeLocation(FVector(0, 0, 25));
	numText->SetRelativeRotation(FRotator(90, 0, 180));
	numText->SetRelativeScale3D(FVector(2));
	numText->SetHorizontalAlignment(EHTA_Center);
    numText->SetVerticalAlignment(EVRTA_TextCenter);
	numText->SetTextRenderColor(FColor::Blue);
	numText->SetText(FText::FromString(""));

	cubeMesh ->OnClicked().AddDynamic(this, &AMineBasic::Click);
}

// Called when the game starts or when spawned
void AMineBasic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMineBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

