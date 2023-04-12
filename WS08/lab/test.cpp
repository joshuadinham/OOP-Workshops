#include "Animation.h"
#include "Media.h"
#include "Video.h"
#include "VRVideo.h"
#include <iostream>

using namespace sdds;
using namespace std;

int main()
{
	VRVideo oculusRift;
	VRVideo SteamVR(200, "SteamVR");
	cout << "Enter your vr setup - <length>,<name>" << endl;
	cin >> SteamVR;
	cout << oculusRift;
	return 0;
}