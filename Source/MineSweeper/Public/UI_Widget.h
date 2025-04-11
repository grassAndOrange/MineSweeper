// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "Blueprint/UserWidget.h"
#include "UI_Widget.generated.h"
/**
 * 
 */
UCLASS()
class MINESWEEPER_API UUI_Widget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UUI_Widget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;
private:
	UPROPERTY(Meta=(BindWidget))
	UButton* ButtonLeft;
	UPROPERTY(Meta = (BindWidget))
	UButton* ButtonRight;
	
	void OnStartButtonClicked();
	//virtual bool Initialize() override;
};
