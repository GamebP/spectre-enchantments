#pragma once

typedef struct final {
	int Controller;
	bool CloseEnnemy;
	bool vischeck;
	int AimBoneInt;
	int BoxStyle;
	int LineStyle;
	int Endpoint;
	bool ShowTrademarks;
	bool PerformanceMod;
	float FovColor[3];
	float FovColorCR[3];
	float CrosshairColor[3];
	float AimingLineColor[3];
	float BoxColor[3];
	float SnaplineColor[3];
	float SkeletonColor[3];
	float BoxColorVis[3];
	float SnaplineColorVis[3];
	float SkeletonColorVis[3];
	int AimKey;
	bool ColorPreset;
	bool Crosshair;
	bool AimingLine;
	bool ShowDistance;
	bool ShowMenu;
	bool Esp;
	bool Esp_line;
	bool outline;
	bool Esp_Skeleton;
	bool Aimbot;
	bool TriggerBot;
	bool EINA;
	bool Controllermod;
	bool RadarESP;
	bool memoryaim;
	bool debug;
	bool speedhack;
	bool RandoAim;
	bool isaimbotting;
	bool ColorAdjuster;
	bool ShowFOV;
	bool RectFOV;
	bool RectFOVCL;
	bool ShowFOVCL;
	bool AimHaveTarget;
	bool CloseRange;
	bool VisibleCheck;
	bool AimPrediction;
	bool InstantRevive;
	int VisDist;
	float AimFOV;
	float AimFOVCloseRange;
	int aimkey;
	int hitbox;
	int aimkeypos;
	int hitboxpos;
	int MaxAimDistance;
	bool AimLock;
	bool DistanceESP;
	int MaxEspDistance;
	int CloseRangeDistance;

	int AimSpeedX;
	int AimSpeedY;
	int AimSpeedXCloseRange;
	int AimSpeedYCloseRange;

	int TimeBeepProche;
	int TimeBeepMoyen;
	int TimeBeepLoin;
	bool SoundEsp;
	bool Chams;
	int RadarSize;
	bool ShowEnnemyAmmo;
	bool UseCustomCrKey;
} SETTINGS;

extern SETTINGS Settings;

namespace SettingsHelper
{
	VOID LoadSavedConfig();
	VOID SaveConfig();
	VOID LoadDefaultConfig();
}