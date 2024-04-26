#pragma once
#include <Windows.h>

#define OFFSET_UWORLD 0xe11fdc8 // 0xe11fdc8

namespace OFFSETS
{
    uintptr_t Gameinstance = 0x1b8;
    uintptr_t LocalPlayers = 0x38;
    uintptr_t PlayerController = 0x30;
    uintptr_t LocalPawn = 0x330;
    uintptr_t PlayerState = 0x2A8;
    uintptr_t RootComponet = 0x190;
    uintptr_t PersistentLevel = 0x30;
    uintptr_t ActorCount = 0xA0;
    uintptr_t AActor = 0x98;
    uintptr_t CurrentActor = 0x8;
    uintptr_t Mesh = 0x310;
    uintptr_t Revivefromdbnotime = 0x4250;
    uintptr_t LocalActorPos = 0x128;
    uintptr_t ComponetToWorld = 0x240;
    uintptr_t BoneArray = 0x5b8;
    uintptr_t Velocity = 0x170;
    uintptr_t PawnPrivate = 0x300;
    uintptr_t PlayerArray = 0x10C0;
    uintptr_t relativelocation = 0x128;
    uintptr_t LastFireTime = 0xAB0;
    uintptr_t LastFireTimeVerified = 0xAB4;
    uintptr_t RelativeLocation = 0x128;
    uintptr_t bIsEquippingWeapon = 0x328;
    uintptr_t bIsReloadingWeapon = 0x329;
    uintptr_t currentweapon = 0x868;
    uintptr_t IsDBNO = 0x4250;
    uintptr_t Dying = 0x6f8;
    uintptr_t TeamId = 0x10e8;
}