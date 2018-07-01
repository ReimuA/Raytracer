/*
** Raytracer by ReimuA
*/

#pragma once

class Color {
public:
	int r;
	int g;
	int b;
	int a;
	Color(int r = 0, int g = 0, int b = 0, int a = 0);
	Color(const Color &color);
	~Color();
};
