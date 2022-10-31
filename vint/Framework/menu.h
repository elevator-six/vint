#pragma once

namespace Menu {
	bool menu_open = true;
	FVector2D pos = { 300, 300 };
	int tab = 0;

	void menu_tick()
	{
		Handle();

		if (GetAsyncKeyState((DWORD)VK_INSERT) & 1) {
			menu_open = !menu_open;
		}


		if (Window(EncryptString("VINT - v0.0.2"), &pos, FVector2D{ 350.0f, 450.0f }, menu_open))
		{
			if (ButtonTab(EncryptString("VISUALS"), FVector2D{ 110, 25 }, tab == 0)) tab = 0;
			if (ButtonTab(EncryptString("MISC"), FVector2D{ 110, 25 }, tab == 1)) tab = 1;
			NextColumn(130.0f);

			if (tab == 0)
			{
				Checkbox(EncryptString("Box ESP"), &Vint::Global::EspSettings::box_esp);
				Checkbox(EncryptString("Head ESP"), &Vint::Global::EspSettings::head_esp);
				Checkbox(EncryptString("Skel ESP"), &Vint::Global::EspSettings::skel_esp);
				Checkbox(EncryptString("Head ESP"), &Vint::Global::EspSettings::head_esp);
				Checkbox(EncryptString("Line ESP"), &Vint::Global::EspSettings::line_esp);
				Checkbox(EncryptString("Name ESP"), &Vint::Global::EspSettings::name_esp);
				Text(EncryptString(" "));
				Checkbox(EncryptString("Chams ESP"), &Vint::Global::ChamsSettings::enabled);
				Checkbox(EncryptString("Chams Always"), &Vint::Global::ChamsSettings::always);
				Checkbox(EncryptString("Hideteam"), &Vint::Global::ChamsSettings::hideteam);
				Text(EncryptString(" "));
				ColorPicker(EncryptString("Chams Color"), &Vint::Global::ChamsSettings::chams_color);
			}

			if (tab == 1)
			{
				Checkbox(EncryptString("Skin Changer"), &Vint::Global::MiscSettings::skinchanger);
				Checkbox(EncryptString("Bunny Hop"), &Vint::Global::MiscSettings::bunnyhop);
				Checkbox(EncryptString("FOVChanger"), &Vint::Global::MiscSettings::fovchanger);

			}
		}
		Render();
		Draw_Cursor(menu_open);
	}
}