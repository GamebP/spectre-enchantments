#include <XInput.h>
#pragma comment(lib, "XInput.lib")
namespace Controller
{
	class XboxController
	{
	private:
		XINPUT_STATE _controllerState;
		int _controllerNum;
	public:
		XboxController(int playerNumber);
		XINPUT_STATE GetControllerState();
		bool CheckConnection();
	};

	XboxController::XboxController(int playerNumber)
	{
		// Set the Controller Number
		_controllerNum = playerNumber - 1;
	}

	XINPUT_STATE XboxController::GetControllerState()
	{
		// Zeroise the state
		ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

		// Get the state
		XInputGetState(_controllerNum, &_controllerState);

		return _controllerState;
	}

	bool XboxController::CheckConnection()
	{
		// Zeroise the state
		ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

		// Get the state
		DWORD Result = XInputGetState(_controllerNum, &_controllerState);

		if (Result == ERROR_SUCCESS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



#define XINPUT_GAMEPAD_TRIGGER_THRESHOLD    30
	XboxController* Player1 = new XboxController(1);
	void POC()
	{
	entry:

			if (Player1->CheckConnection())
			{
				std::cout << "	 Succesfully connected to controller\n";
				std::cout << "	 Please press your right trigger\n";
				while (!Player1->GetControllerState().Gamepad.bRightTrigger)
				{
					Sleep(100);
				}
				std::cout << "	[+] Right Trigger Pulled\n";
				std::cout << "	 Please press your left trigger\n";
		
				while (!Player1->GetControllerState().Gamepad.bLeftTrigger)
				{
					Sleep(100);
				}
				std::cout << "	[+] Left Trigger Pulled\n";
				std::cout << "	[+] Test finished !\n";
			}
			else
			{
				std::cout << "	 Please make sure to plug your controller\n";
				Sleep(5000);
				goto entry;
			}


			
	}
	bool IsPressingRightTrigger()
	{
		if (Player1->GetControllerState().Gamepad.bRightTrigger)
		{
			return true;
		}
		return false;
	}
	bool IsPressingLeftTrigger()
	{
		if (Player1->GetControllerState().Gamepad.bLeftTrigger)
		{
			return true;
		}
		return false;
	}

}
