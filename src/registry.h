/*
 * Registry Management Header
 */

#ifndef REGISTRY_H
#define REGISTRY_H

#include <windows.h>

BOOL IsAutostartEnabled(void);
BOOL EnableAutostart(void);
BOOL DisableAutostart(void);
BOOL ToggleAutostart(void);

#endif // REGISTRY_H

