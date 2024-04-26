

#include "ExternalUtils.h"


float
TextSpaceLine = 90.f,
SpaceLineOne = 120.f,
SpaceLineTwo = 280.f,
SpaceLineThr = 420.f;

bool playerfly = false;
float bigbellynerds = 20.0f;

bool charge;
bool rapiddmr;

bool enemiesarround = true;
int enemyID = 0;
int enemyIDvis = 0;
int CloseRangeDistanceID = 0;
float CloseRangeDistance = 50.f;
float width = 0.5f;
bool InLobby;
float CachedFOV;

bool lootesp;
bool caresp;
bool chestesp;
bool stamina;
bool common{ false };

bool isLobby;
bool busnerds = false;
bool crouchingepse = false;
bool uncommon{ false };
bool rare{ false };
bool epic{ false };
bool legendary{ false };
bool mythic{ false };

bool vischeck = true;

bool exploits = false;
bool idkkk = false;

bool crouched = false;

bool fuel = false;
bool filledfov = false;
bool inffule = false;

bool teamcheck;

bool chams = false;

float BigPlayersScale = 2.50;


float espdistance = 100.f;


DWORD_PTR closestPawn = NULL;

bool weaponesp;
static int headnerds;
float Cached;
bool DynamicFov;
bool levelesp;
bool boxnerds = false;
bool killesp;
bool ShowMenu = true;
bool Smooth = false;
bool Esp = true;
Vector3 localactorpos;
bool stmaninerds = false;
bool vehiclefov = false;
Vector3 Location;
bool Esp_box = true;
static bool AnglesResetted = true;
bool ESPFOVCircle = false;
bool fovfill = false;
bool fovsquare = false;
int AimBoneInt;
bool sharkesp = false;
bool shieldcrates = false;
bool shieldesp = false;
bool floppaesp = false;
bool Esp_distance = false;
bool lamaesp = false;
bool Esp_fill = false;
bool vendingmachine = false;
bool invisible = false;
bool reloading = false;
bool radar;
bool Esp_crosshair = true;
double zoom;
bool Esp_line = false;
bool Esp_cline = false;
bool threeeeeed = false;
bool RandoAim = false;
float flRadarPos_x = 120;
float flRadarPos_y = 120;
float iSavedRadarX;
float iSavedRadarY;
bool box3d = false;
bool Esp_triangle = false;
int	RadarStyle = 0;
bool Esp_trifill = false;
bool topointfivehours = false;
bool Esp_teambox = false;
bool spinbot = false;
bool Esp_Skeleton = false;
bool rapidaug = false;
bool carfly = false;
bool while_rotating;
bool Esp_corner = false;
bool aimbotanimales = false;
bool bigplayers = false;
bool square = false;
bool crosshair = false;
bool supplycrate = false;
bool Bullettp = false;
bool AimNERD = false;
float lootnerddistance = 50.0f;
bool aimair = false;
bool niggerfovchanger = false;
bool pickheadpos = false;
int Spin = 0;
bool boatspeed = false;
bool instantreload = false;

bool carto = false;
bool circle = false;
bool Esp_Dot = false;
bool Aimbot = true;
bool speedvehicle = false;
bool Lock_Line = false;
bool memoryaim = false;
float bA1mb0tSm00th1ngV4lue = 3;
float FOVChangerValue = 81.0f;
bool debug = false;

bool instantreboot;

bool nazi = false;

bool isVis;

float AimFOV = 174;
float wheredoweaim = 0;
int smooth = 5;

bool PlatFormEsp;
bool nameesp;
bool espnamenerds;
bool showteam = false;
bool animals;
bool activeweapon = false;
bool ammobox;
bool SuppyCrate;
bool ammmoesp;

bool targetlines = false;
bool platform;
bool nameeesp = false;

Vector3 LocalRelativeLocation;
uint64_t LocalRootcomp;

bool gravity = false;

static int aimkey;
static int aimlocataion;
static int hitbox;

float gravitynerds = 50.0f;


bool fly = false;

float boatmulti = 1.0f;

bool walk = false;
bool vehspooed = false;
bool IgnoreAllFallingDamage = false;
bool fastjump = false;
bool boatspeedd = false;
bool head;
bool chest;
bool pelvis;
bool legs;

namespace SettingsColor {
	static ImColor Esp;
	static ImColor Esp_Radar;
	static ImColor Esp_NotVisible;


}

namespace CachedCamera {
	double Pitch;
	double Yaw;
	uintptr_t ptr;
}

/*
*/