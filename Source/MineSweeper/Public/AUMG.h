// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UI_Widget.h"
#include "AUMG.generated.h"
UCLASS()
class MINESWEEPER_API AAUMG : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAUMG();
	UPROPERTY()
	UUserWidget* MainWidgetInstance;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUI_Widget> MainWidgetClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
