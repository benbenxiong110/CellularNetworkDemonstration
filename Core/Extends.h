#include "StdInclude.h"

namespace CellularNetworkDemonstration {
    SDL_FORCE_INLINE SDL_bool SDL_PointInRect(const SDL_Point *p, const SDL_Rect *r) {
        return ( ( p->x >= r->x ) && ( p->x < ( r->x + r->w ) ) &&
            ( p->y >= r->y ) && ( p->y < ( r->y + r->h ) ) ) ? SDL_TRUE : SDL_FALSE;
    }

    SDL_FORCE_INLINE SDL_bool SDL_PointInRect(const SDL_Point &p, const SDL_Rect &r) {
        return ( ( p.x >= r.x ) && ( p.x < ( r.x + r.w ) ) &&
            ( p.y >= r.y ) && ( p.y < ( r.y + r.h ) ) ) ? SDL_TRUE : SDL_FALSE;
    }

    SDL_FORCE_INLINE SDL_bool SDL_PointInRect(const int &x, const int &y, const SDL_Rect &r) {
        return ( ( x >= r.x ) && ( x < ( r.x + r.w ) ) &&
            ( y >= r.y ) && ( y < ( r.y + r.h ) ) ) ? SDL_TRUE : SDL_FALSE;
    }
}