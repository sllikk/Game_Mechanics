#pragma once

#include "DevMacros.h"
#include "CoreMinimal.h"

// Physics Macros
#define PHYSICS_HANDLE_TRACE ECC_GameTraceChannel1
#define DEBUG_TRACE ECC_GameTraceChannel2
#define PROJECTILE_TRACE ECC_GameTraceChannel3

// DrawDebugHelpers Macros
/* NULL it is param  float LifeTime, uint8 DepthPriority, */
#define TICK_DRAW_DEBUG_LINE(Start, End, Color) if(GetWorld() != nullptr) DrawDebugLine(GetWorld(), Start, End, Color ,false, NULL, NULL)
#define TICK_DRAW_DEBUG_POINT(Location, Size ,Color) if(GetWorld() != nullptr) DrawDebugPoint(GetWorld(), Location, Size, Color ,false, NULL, NULL)
#define TICK_DRAW_DEBUG_COORDINATE_SYSTEM(AxisLoc, AxisRot, Size) (GetWorld()) DrawDebugCoordinateSystem(GetWorld(), AxisLoc, AxisRot, false, NULL, NULL)
#define TICK_DRAW_DEBUG_SPHERE(Center, Radius, Color) if(GetWorld() != nullptr) DrawDebugSphere(GetWorld(), Origin, Radius, 16, Color ,false, NULL, NULL)
#define TICK_DRAW_DEBUG_CAPSULE(Center, HalfHeight, Radius ,Rotator ,Color) if(GetWorld() != nullptr) DrawDebugCapsule(GetWorld(), Center, HalfHeight, Radius,Rotator,Color ,false, NULL, NULL)
#define TICK_DRAW_DEBUG_BOX(Origin, Extern, Color) if(GetWorld() != nullptr) DrawDebugBox(GetWorld(), Origin, Extern, Color , false, NULL, NULL)
#define TICK_DRAW_DEBUG_BOXR(Origin, Extern, Quat, Color) if(GetWorld() != nullptr) DrawDebugBox(GetWorld(), Origin, Extern, Quat , Color ,false, NULL, NULL)
#define TICK_DRAW_DEBUG_CYLINDER(Start, End, Radius, Color) if(GetWorld() != nullptr) DrawCylinder(GetWorld(), Start, End, 16 Color ,false, NULL, NULL)
#define TICK_DRAW_DEBUG_STRING(Location, String, Size, Color) if(GetWorld() != nullptr) DrawDebugString(GetWorld(), Location, nullptr, Color, 0, Size) 

/* Time it is param  float LifeTime */
#define TIMER_DRAW_DEBUG_LINE(Start, End, Color, Time) if(GetWorld() != nullptr) DrawDebugLine(GetWorld(), Start, End, Color ,false, Time, NULL)
#define TIMER_DRAW_DEBUG_POINT(Location, Size ,Color, Time) if(GetWorld() != nullptr) DrawDebugPoint(GetWorld(), Location, Size, Color ,false, Time, NULL)
#define TIMER_DRAW_DEBUG_COORDINATE_SYSTEM(AxisLoc, AxisRot, Size, Time) (GetWorld()) DrawDebugCoordinateSystem(GetWorld(), AxisLoc, AxisRot, false, Time, NULL)
#define TIMER_DRAW_DEBUG_SPHERE(Center, Radius, Color, Time) if(GetWorld() != nullptr) DrawDebugSphere(GetWorld(), Origin, Radius, 16, Color ,false, Time, NULL)
#define TIMER_DRAW_DEBUG_CAPSULE(Center, HalfHeight, Radius ,Rotator ,Color, Time) if(GetWorld() != nullptr) DrawDebugCapsule(GetWorld(), Center, HalfHeight, Radius,Rotator,Color ,false, Time, NULL)
#define TIMER_DRAW_DEBUG_BOX(Origin, Extern, Color, Time) if(GetWorld() != nullptr) DrawDebugBox(GetWorld(), Origin, Extern, Color , false, Time, NULL)
#define TIMER_DRAW_DEBUG_BOXR(Origin, Extern, Quat, Color, Time) if(GetWorld() != nullptr) DrawDebugBox(GetWorld(), Origin, Extern, Quat , Color ,false, Time, NULL)
#define TIMER_DRAW_DEBUG_CYLINDER(Start, End, Radius, Color, Time) if(GetWorld() != nullptr) DrawCylinder(GetWorld(), Start, End, 16 Color ,false, Time, NULL)
#define TIMER_DRAW_DEBUG_STRING(Location, String, Size, Duration , Color) if(GetWorld() != nullptr) DrawDebugString(GetWorld(), Location, nullptr, Color, Duration, Size) 




