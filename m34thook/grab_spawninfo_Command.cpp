#include "mh_defs.hpp"

#include "game_exe_interface.hpp"
#include "doomoffs.hpp"
#include "meathook.h"
#include "cmdsystem.hpp"
#include "idtypeinfo.hpp"
#include "eventdef.hpp"
#include "scanner_core.hpp"

#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <snaphakalgo.hpp>

//#include "idLib.hpp"
#if 0
namespace idMath {
void SinCos(float a, float& s, float& c)
{

	//byte_angle_t by = rad2byte(a);

	// DG: non-MSVC version
	s = sinf(a);
	c = cosf(a);

}

const float	PI				= 3.14159265358979323846f;

const float	M_DEG2RAD		= PI / 180.0f;
const float	M_RAD2DEG		= 180.0f / PI;

}

#endif
struct idVec3 {
	float x, y, z;
	void Set(float _x, float _y, float _z){
		x=_x;
		y=_y;
		z=_z;
	}
};

struct idMat3 {
	idVec3			mat[ 3 ];
};
class idAngles
{
public:
	float			pitch;
	float			yaw;
	float			roll;
	idMat3 ToMat3() const;
};

//#define DEG2RAD(a)				( (a) * idMath::M_DEG2RAD )

idMat3 idAngles::ToMat3() const
{
	idMat3 mat;
	double sr, sp, sy, cr, cp, cy;
	using namespace sh::math;
	
	
	sincos( DEG2RAD( yaw ), sy, cy );
	sincos( DEG2RAD( pitch ), sp, cp );
	sincos( DEG2RAD( roll ),sr, cr );

	mat.mat[ 0 ].Set( cp * cy, cp * sy, -sp );
	mat.mat[ 1 ].Set( sr * sp * cy + cr * -sy, sr * sp * sy + cr * cy, sr * cp );
	mat.mat[ 2 ].Set( cr * sp * cy + -sr * -sy, cr * sp * sy + -sr * cy, cr * cp );

	return mat;
}


static char clipboard_buffer[1024];

const char* get_clipboard_data() {
	
	if (!OpenClipboard(NULL)) 
		return nullptr;
	HANDLE cbhandle = GetClipboardData(CF_TEXT);
	CloseClipboard();
	return (const char*)cbhandle;
}

void set_clipboard_data(const char* dat) {
	if (!OpenClipboard(NULL)) 
		return;
	size_t datsize=strlen(dat)+1;

	HGLOBAL mem = GlobalAlloc( GMEM_MOVEABLE, datsize );
	char	*str = (char *)GlobalLock( mem );

	memcpy(str, dat,datsize);
	GlobalUnlock( str );
	EmptyClipboard();
	SetClipboardData(CF_TEXT,mem);
	CloseClipboard();
}

void cmd_mh_spawninfo(idCmdArgs* args) {
	
	idCmd::execute_command_text("getviewpos");

	if (!OpenClipboard(NULL)) 
		return;
	HANDLE cbhandle = GetClipboardData(CF_TEXT);

	float x, y, z;
	float yaw, pitch;

	sscanf_s((const char*)cbhandle, "%f %f %f %f %f", &x, &y, &z, &yaw, &pitch);
	idAngles angles{pitch, yaw, .0};
	idMat3 mat = angles.ToMat3();
	const char* fmtstr = "spawnOrientation = {\n\tmat = {\n\t\tmat[0] = {\n\t\t\tx = %f;\n\t\t\ty = %f;\n\t\t\tz = %f;\n\t\t}\n\t\tmat[1] = {\n\t\t\tx = %f;\n\t\t\ty = %f;\n\t\t\tz = %f;\n\t\t}\n\t\tmat[2] = {\n\t\t\tx = %f;\n\t\t\ty = %f;\n\t\t\tz = %f;\n\t\t}\n\t}\n}\nspawnPosition = {\n\tx = %f;\n\ty = %f;\n\tz = %f;\n}";
	auto& m = mat.mat;
	sprintf_s(clipboard_buffer, fmtstr, m[0].x, m[0].y, m[0].z, m[1].x, m[1].y, m[1].z, m[2].x, m[2].y, m[2].z, x, y, z);
	HGLOBAL mem = GlobalAlloc( GMEM_MOVEABLE, 2048 );
	char	*str = (char *)GlobalLock( mem );

	memcpy(str, clipboard_buffer, 2048);
	GlobalUnlock( str );
	EmptyClipboard();
	SetClipboardData(CF_TEXT,mem);
	CloseClipboard();
}

void cmd_mh_offset(idCmdArgs* args) {
	//handle if no clipboard data
	if (!OpenClipboard(NULL))
		return;
	//get old posi from clipbaod and save it to variables
	HANDLE cbhandle = GetClipboardData(CF_TEXT);
	float oldX, oldY, oldZ;
	sscanf_s((const char*)cbhandle, "%f %f %f", &oldX, &oldY, &oldZ);
	EmptyClipboard();
	CloseClipboard();

	//get new position data
	idCmd::execute_command_text("getviewpos");

	if (!OpenClipboard(NULL))
		return;
	
	cbhandle = GetClipboardData(CF_TEXT);

	float x, y, z;

	sscanf_s((const char*)cbhandle, "%f %f %f", &x, &y, &z);

	//calculate offset
	float offsetX, offsetY, offsetZ;

	offsetX = (oldX - x) * -1;
	offsetY = (oldY - y) * -1;
	offsetZ = (oldZ - z) * -1;

	//idLib::Printf("printing previous pos: %f %f %f\n", oldX, oldY, oldZ);
	//idLib::Printf("printing current pos: %f %f %f\n", x, y, z);
	//idLib::Printf("printing offsets: %f %f %f\n", offsetX, offsetY, offsetZ);
	//format and copy to clipboard
	const char* fmtstr = "item[] = {\n\t\t\t\t\toffsetDestination = {\n\t\t\t\t\t\tx = %f;\n\t\t\t\t\t\ty = %f;\n\t\t\t\t\t\tz = %f;\n\t\t\t\t\t}\n\t\t\t\t\ttimeSec = 0;\n\t\t\t\t\tspeedSec = 2.5;\n\t\t\t\t}";
	sprintf_s(clipboard_buffer, fmtstr, offsetX, offsetY, offsetZ);
	HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, 2048);
	char* str = (char*)GlobalLock(mem);

	memcpy(str, clipboard_buffer, 2048);
	GlobalUnlock(str);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, mem);
	CloseClipboard();
}

/*void cmd_mh_offset(idCmdArgs* args) {

	idCmd::execute_command_text("getviewpos");

	if (!OpenClipboard(NULL))
		return;
	HANDLE cbhandle = GetClipboardData(CF_TEXT);

	float x, y, z;

	sscanf_s((const char*)cbhandle, "%f %f %f", &x, &y, &z);

	const char* fmtstr = "Offset = {\n\tx = %f\n\ty = %f\n\tz = %f\n}";
	sprintf_s(clipboard_buffer, fmtstr, x, y, z);
	HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, 2048);
	char* str = (char*)GlobalLock(mem);

	memcpy(str, clipboard_buffer, 2048);
	GlobalUnlock(str);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, mem);
	CloseClipboard();
}*/


void cmd_mh_ang2mat(idCmdArgs* args) {
	double inv1 = .0;
	if (args->argc > 1) {
		inv1 = atof(args->argv[1]);
	}
	double inv2 = .0f;
	if (args->argc > 2) {
		inv2 = atof(args->argv[2]);
	}

	double inv3 = .0f;
	if (args->argc > 3) {
		inv3 = atof(args->argv[3]);
	}
	idAngles angles{ (float)inv1, (float)inv2, (float)inv3 };
	idMat3 mat = angles.ToMat3();
	//copypaste
	const char* fmtstr = "{\n\tmat = {\n\t\tmat[0] = {\n\t\t\tx = %f;\n\t\t\ty = %f;\n\t\t\tz = %f;\n\t\t}\n\t\tmat[1] = {\n\t\t\tx = %f;\n\t\t\ty = %f;\n\t\t\tz=%f;\n\t\t}\n\t\tmat[2] = {\n\t\t\tx = %f;\n\t\t\ty = %f;\n\t\t\tz = %f;\n\t\t}\n\t}\n}\n";
	auto& m = mat.mat;
	sprintf_s(clipboard_buffer, fmtstr, m[0].x, m[0].y, m[0].z, m[1].x, m[1].y, m[1].z, m[2].x, m[2].y, m[2].z);
	set_clipboard_data(clipboard_buffer);
}
