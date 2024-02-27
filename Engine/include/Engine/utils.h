#ifndef NUCTE_NS
// NUCTE (NuclearTeam) _NS (_NameSpace)
#define NUCTE_NS NuclearTeam_Namespace 
#endif

#ifndef NE_ASSERT
#include <assert.h>
#define NE_ASSERT(_EXPR)            assert(_EXPR)
#endif

#include "Engine/Input/InputManager.h"

namespace NUCTE_NS {
    extern InputManager* m_InputManager;
}
