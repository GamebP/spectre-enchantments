#include "includesN.h"

SETTINGS Settings = { 0 };

namespace SettingsHelper
{
	VOID SaveConfig()
	{
		CHAR path[0xFF];
		GetTempPathA(sizeof(path) / sizeof(path[0]), path);
		strcat(path, ("Config.cfg"));

		auto file = fopen(path, ("wb"));
		if (file) {
			fwrite(&Settings, sizeof(Settings), 1, file);
			fclose(file);
		}
	}
	VOID LoadDefaultConfig()
	{
		Settings.PerformanceMod = false;
		Settings.Controller;
		Settings.CloseEnnemy = false;
		Settings.vischeck = true;
		Settings.AimBoneInt;
		Settings.BoxStyle = 0;
		Settings.LineStyle = 0;
		Settings.Endpoint = 1;
		Settings.AimPrediction = false;

		Settings.ShowTrademarks = true;
		
	Settings.FovColor[4];
	Settings.FovColorCR[4];
	Settings.CrosshairColor[4];
	Settings.AimingLineColor[4];
	Settings.BoxColor[4];
	Settings.SnaplineColor[4];
	Settings.SkeletonColor[4];
	Settings.BoxColorVis[4];
	Settings.SnaplineColorVis[4];
	Settings.SkeletonColorVis[4];
	
		Settings.AimKey;
		Settings.ColorPreset = true;
		Settings.Crosshair = true;
		Settings.AimingLine = false;
		Settings.ShowDistance = false;
		Settings.ShowMenu = true;
		Settings.Esp = true;
		Settings.Esp_line = true;
		Settings.outline = true;
		Settings.Esp_Skeleton = true;
		Settings.Aimbot = true;
		Settings.TriggerBot = false;
		Settings.EINA = true;
		//Settings.Controllermod = false;
		Settings.RadarESP = true;
		Settings.memoryaim = false;
		Settings.debug = false;
		Settings.speedhack = false;
		Settings.RandoAim = false;
		Settings.isaimbotting;
		Settings.ColorAdjuster;
		Settings.ShowFOV = true;
		Settings.RectFOV = false;
		Settings.RectFOVCL = false;
		Settings.ShowFOVCL = true;
		Settings.AimHaveTarget = true;
		Settings.CloseRange = true;
		Settings.VisibleCheck = true;
		Settings.InstantRevive = false;
		Settings.VisDist = 500;
		Settings.AimFOV = 300;
		Settings.AimFOVCloseRange = 300;
		Settings.MaxAimDistance = 100;
		Settings.AimLock = true;
		Settings.aimkey;
		Settings.hitbox;
		Settings.aimkeypos = 3;
		Settings.hitboxpos = 0;
		Settings.DistanceESP = true;
		Settings.MaxEspDistance = 300;
		Settings.CloseRangeDistance = 5;

		Settings.AimSpeedX = 10.0f;
		Settings.AimSpeedY = 10.0f;
		Settings.AimSpeedXCloseRange = 6.0f;
		Settings.AimSpeedYCloseRange = 6.0f;
		Settings.Chams = true;
		Settings.RadarSize = 250;
		Settings.TimeBeepProche = 250;
		Settings.TimeBeepMoyen = 500;
		Settings.TimeBeepLoin = 1000;
		Settings.SoundEsp = false;
		Settings.ShowEnnemyAmmo = true;
		Settings.UseCustomCrKey = false;
	}
	VOID LoadSavedConfig()
	{
		CHAR path[0xFF] = { 0 };
		GetTempPathA(sizeof(path) / sizeof(path[0]), path);
		strcat(path, ("Config.cfg"));

		auto file = fopen(path, ("rb"));
		if (file) {
			fseek(file, 0, SEEK_END);
			auto size = ftell(file);

			if (size == sizeof(Settings)) {
				fseek(file, 0, SEEK_SET);
				fread(&Settings, sizeof(Settings), 1, file);
				fclose(file);
			}
			else {
				fclose(file);
				LoadDefaultConfig();
			}
		}
		else {
			LoadDefaultConfig();
		}
	}

}