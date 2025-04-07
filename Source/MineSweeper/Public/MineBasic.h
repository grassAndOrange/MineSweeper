// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/TextRenderComponent.h>
#include "MineBasic.generated.h"


UCLASS()
class MINESWEEPER_API AMineBasic : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* cubeMesh;
	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* flagMesh;
	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* bombMesh;
	UPROPERTY(VisibleDefaultsOnly)
	UTextRenderComponent* numText;


	
public:	
	// Sets default values for this actor's properties
	AMineBasic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool isBomb;
	class AMineGenerator* Grid;
	void Click(UPrimitiveComponent* ClickedComp, FKey ButtomnPressed);
};
