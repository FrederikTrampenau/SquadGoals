#pragma once

#define UE_PRINT_TEXT(Log, Value, Color) \
if(GEngine) \
{ \
GEngine->AddOnScreenDebugMessage(-1, 0.2f, Color, FString::Printf(TEXT(Log), Value)); \
}

#define UE_PRINT_TEXT(Log, Color) \
if(GEngine) \
{ \
GEngine->AddOnScreenDebugMessage(-1, 0.2f, Color, FString::Printf(TEXT(Log))); \
}