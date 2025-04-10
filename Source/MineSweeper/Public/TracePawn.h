// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MineBasic.h"
#include "TracePawn.generated.h"
class UUI_Widget;
UCLASS()
class MINESWEEPER_API ATracePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATracePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	AMineBasic* FocuseCube;
	FString before = "";
	FString now = "";
	void Trace(FVector Start,FVector End);
	void Click_R();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> UIWidgetClass;
private:


	UPROPERTY()
	UUserWidget* UIWidgetInstance;
};
