#pragma once

namespace Menu {
	bool menu_open = false;
	FVector2D pos = { 300, 300 };
	int tab = 0;

	void menu_tick()
	{
		Handle();

		if (GetAsyncKeyState((DWORD)VK_INSERT) & 1) {
			menu_open = !menu_open;
		}


		if (Window(EncryptString("vint - v0.0.2"), &pos, FVector2D{ 450.0f, 450 }, menu_open))
		{
			ColorPicker(EncryptString("Chams Color"), &Vint::Global::ChamsSettings::chams_color);

		}
		Render();
		Draw_Cursor(menu_open);
	}
}