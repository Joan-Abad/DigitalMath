#pragma once

#define DIGITALMATH_EXPORT

#ifdef DIGITALMATH_EXPORT
    #define DIGITALMATH_API __declspec(dllexport)
#else
    #define DIGITALMATH_API __declspec(dllimport)
#endif