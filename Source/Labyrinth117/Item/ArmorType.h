// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ArmorType : uint8
{
	HEAD = 0 UMETA(DisplayName = "Head"),
	BODY = 1 UMETA(DisplayName = "Body"),
	FOOT = 2 UMETA(DisplayName = "Foot")
};

