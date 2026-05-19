#pragma once

#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true); 
#define DRAW_SPHERE_SINGLE_FRAME(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red);
#define DRAW_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f);
#define DRAW_LINE_SINGLE_FRAME(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red);
#define DRAW_POINT(Position) if (GetWorld()) DrawDebugPoint(GetWorld(), Position, 30.f, FColor::Red, true);
#define DRAW_POINT_SINGLE_FRAME(Position) if (GetWorld()) DrawDebugPoint(GetWorld(), Position, 30.f, FColor::Red);
#define DRAW_VECTOR(StartLocation, EndLocation) if(GetWorld()) \
{ \
DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f); \
DrawDebugPoint(GetWorld(), EndLocation, 30.f, FColor::Red, true); \
}
#define DRAW_VECTOR_SINGLE_FRAME(StartLocation, EndLocation) if(GetWorld()) \
{ \
DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red); \
DrawDebugPoint(GetWorld(), EndLocation, 30.f, FColor::Red); \
}

#define DRAW_NEW_SPHERE(Location, Color) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, 12, Color, true);
#define DRAW_COORDINATE_SYSTEM(Location, Rotation) if (GetWorld()) DrawDebugCoordinateSystem(World, Location, Rotation, 100.f, true, -1.f, 0, 1.f);
#define DRAW_STRING(Location, String) if (GetWorld()) DrawDebugString(World, Location, String, this, FColor::Blue, -1.f, true, 1);

// MultiLine MACRO 작성 시에는 "\" 문자를 해당 Line의 마지막 기호로 위치시킨다.
// "\" 문자는 MACRO define이 아직 끝나지 않았음을 의미한다.
// #define DRAW_SPHERE(Location) \
// 	if (GetWorld()) { \
// 		DrawDebugSphere(GetWorld(), Location, 25.f, 12, FColor::Red, true); \
// 	} 