// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_Widget.h"

UUI_Widget::UUI_Widget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UUI_Widget::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonLeft = Cast<UButton>(GetWidgetFromName(TEXT("BP_UI")));
	ButtonLeft->OnClicked.AddDynamic(this, &UUI_Widget::OnStartButtonClicked);
}
void UUI_Widget::OnStartButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Start Button Clicked!"));
}



//bool UUI_Widget::Initialize()
//{
//	if (!Super::Initialize())
//	{
//		return false;
//	}
//	ButtonLeft->OnClicked.AddDynamic(this, &UUI_Widget::OnStartButtonClicked);
//	return true;
//
//}
