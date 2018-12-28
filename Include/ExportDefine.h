#pragma once
#ifndef FlyUI_API_OPTION
#define FLYUI_API __declspec(dllexport)
#else
#define FLYUI_API __declspec(dllimport)
#endif