#pragma once
#include "MathUTIS.h"
#include <cmath>
#include <stdint.h>

struct Color
{
	float r;
	float g;
	float b;
	float a;

	Color() = default;
	Color(float r, float g, float b, float a = 0)
	{ this->r = r; this->g = g; this->b = b; this->a = a;}

	float operator [] (unsigned int index) const { return (&r)[index]; }
	float& operator [] (unsigned int index) { return (&r)[index]; }

	//Color operator + (const Color& c) const { return Color{ r + c.r, g + c.g, b + c.b, a + c.a}; }
	//Color operator - (const Color& c) const { return Color{ r - c.r, g - c.g, b - c.b, a - c.a}; }
	//Color operator * (const Color& c) const { return Color{ r * c.r, g * c.g, b * c.b, a * c.a}; }
	//Color operator / (const Color& c) const { return Color{ r / c.r, g / c.g, b / c.b, a / c.a}; }
	//
	//Color operator + (float s) const { return Color{x += s; y += s }; }
	//Color operator - (float s) const { return Color{x -= s; y -= s }; }
	//Color operator * (float s) const { return Color{x *= s; y *= s }; }
	//Color operator / (float s) const { return Color{x /= s; y /= s }; }
	//
	//Color& operator += (const Color& c) { r + c.r, g + c.g, b + c.b, a + c.a; return *this; }
	//Color& operator -= (const Color& c) { r - c.r, g - c.g, b - c.b, a - c.a; return *this; }
	//Color& operator *= (const Color& c) { r * c.r, g * c.g, b * c.b, a * c.a; return *this; }
	//Color& operator /= (const Color& c) { r / c.r, g / c.g, b / c.b, a / c.a; return *this; }
	//
	//Color& operator += (float s) { r + s.r, g + c.g, b + c.b, a + c.a; return *this; }
	//Color& operator -= (float s) { r - s.r, g - c.g, b - c.b, a - c.a; return *this; }
	//Color& operator *= (float s) { r * s.r, g * c.g, b * c.b, a * c.a; return *this; }
	//Color& operator /= (float s) { r / s.r, g / c.g, b / c.b, a / c.a; return *this; }

	static uint8_t Toint(float value) { return static_cast<uint8_t>(Math::Clamp(value, 0.0f, 1.0f) * 255); } 
};
