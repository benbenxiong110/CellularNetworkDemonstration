#pragma once
#include "StdInclude.h"

#define DELETE_IF_EXIST(POINTER) if(POINTER){delete (POINTER);}
#define DELETE_IF_EXIST_TEXTURE(TEXTURE) if(TEXTURE){SDL_DestroyTexture(TEXTURE);}

namespace CellularNetworkDemonstration {



    SDL_FORCE_INLINE void SDL_log(long double num) {
#ifdef DEBUG
        std::cout << num << std::endl;
#endif // DEBUG
    }

    SDL_FORCE_INLINE void SDL_log(const char *str) {
#ifdef DEBUG
        std::cout << str << std::endl;
#endif // DEBUG
    }

    // 判断最标点是否属于在矩形内
    SDL_FORCE_INLINE SDL_bool SDL_PointInRect(const SDL_Point *p, const SDL_Rect *r) {
        return ( ( p->x >= r->x ) && ( p->x < ( r->x + r->w ) ) &&
            ( p->y >= r->y ) && ( p->y < ( r->y + r->h ) ) ) ? SDL_TRUE : SDL_FALSE;
    }

    // 判断最标点是否属于在矩形内
    SDL_FORCE_INLINE SDL_bool SDL_PointInRect(const SDL_Point &p, const SDL_Rect &r) {
        return ( ( p.x >= r.x ) && ( p.x < ( r.x + r.w ) ) &&
            ( p.y >= r.y ) && ( p.y < ( r.y + r.h ) ) ) ? SDL_TRUE : SDL_FALSE;
    }

    // 判断最标点是否属于在矩形内
    SDL_FORCE_INLINE SDL_bool SDL_PointInRect(const int &x, const int &y, const SDL_Rect &r) {
        return ( ( x >= r.x ) && ( x < ( r.x + r.w ) ) &&
            ( y >= r.y ) && ( y < ( r.y + r.h ) ) ) ? SDL_TRUE : SDL_FALSE;
    }

    // 获取坐标点在矩形内相对位置
    SDL_FORCE_INLINE SDL_Point SDL_RelationPoint(const SDL_Point *p, const SDL_Rect *r) {
        return SDL_Point{ p->x - r->x, p->y - r->y };
    }

    // 获取坐标点在矩形内相对位置
    SDL_FORCE_INLINE SDL_Point SDL_DeRelationPoint(const SDL_Point *p, const SDL_Rect *r) {
        return SDL_Point{ r->x + p->x , r->y + p->y };
    }

    // 标准字体系列
    enum TTF_FontFamilySeries {
        // 无衬线字体
        TTF_FONT_SANS_SERIF,
        // 衬线字体
        TTF_FONT_SERIF,
        // 等宽字体
        TTF_FONT_MONOSPACE,

        // 默认字体设置为无衬线字体
        TTF_FONT_DEFAULT = TTF_FONT_SANS_SERIF
    };

    // 渲染字体
    SDL_Texture *TTF_RenderTextTexture(SDL_Renderer *renderer,
        const std::string &message,
        int fontSize,
        SDL_Color *color = nullptr,
        TTF_FontFamilySeries fontFamily = TTF_FONT_DEFAULT);

   


    SDL_FORCE_INLINE void SDL_SetRenderDrawColor_DefalutBackground(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer, 235, 235, 235, 255);
    }

    // 最小化事件
    static const int SDL_MINIMIZE = 0x00000001;

    // 页面切换事件
    static const int SDL_CHANGEVIEW = 0x00000100;
    static const int SDL_CHANGEVIEW_01 = 0x00000101;
    static const int SDL_CHANGEVIEW_02 = 0x00000102;
    static const int SDL_CHANGEVIEW_03 = 0x00000103;
    static const int SDL_CHANGEVIEW_04 = 0x00000104;

    // 演示菜单切换事件

    static const int SDL_DEMO_SIDEBAR = 0x00000200;
    // 基站详细信息显示，data1为int数据，基站id
    static const int SDL_DEMO_SIDEBAR_BASE_STATION = 0x00000201;
    // 移动台详细信息显示，data1为int数据，移动台id
    static const int SDL_DEMO_SIDEBAR_MOBILE_CLIENT = 0x00000202;
    static const int SDL_DEMO_SIDEBAR_KEYBOARD = 0x00000203;
    static const int SDL_DEMO_SIDEBAR_SCREEN = 0x00000204;
    static const int SDL_DEMO_SIDEBAR_CHIPSET = 0x00000205;
}