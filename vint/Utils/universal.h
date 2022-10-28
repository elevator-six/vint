#pragma once

namespace Vint {
	namespace pointers {
		uintptr_t IsProjectileWeapon = 0;
	}

	namespace Global {
		double r;
		double g;
		double b;
		double a;

		namespace aimbot {
			bool enabled = false;
			bool visible_only = false;
			bool smooth = false;

			bool drawfov = true;

			float max_fov = 20.f;
			int aimbot_speed = 7.f;

			int aimkey = 0;

			int aimbone = 0;
		}

		namespace EspSettings {
			bool box_esp = true;
			bool name_esp = false;
			bool skel_esp = false;
			bool head_esp = true;
			bool line_esp = true;
			bool health_esp = true;
			bool dist_esp = false;

			int type = 0;
		}

		namespace ChamsSettings {
			bool enabled = false;
			bool always = false;
			bool hideteam = true;
			FLinearColor chams_color = { 0, 1, 0, 1 };
		}

		namespace misc {
			bool skinchanger = false;
			bool bunnyhop = true;

			bool fovchanger = false;

			int knifeskin = 0;
			int vandalskin = 0;
			int phantomskin = 0;
			int sheriffskin = 0;

			float FOV = 0;
		}
	}
}
