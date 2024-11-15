#pragma once

#define PRINT_TEXT(Log, Value, Color) \
if(GEngine) \
{ \
GEngine->AddOnScreenDebugMessage(-1, 0.2f, Color, FString::Printf(TEXT(Log), Value)); \
}

#define PRINT_TEXT(Log, Color) \
if(GEngine) \
{ \
GEngine->AddOnScreenDebugMessage(-1, 0.2f, Color, FString::Printf(TEXT(Log))); \
}