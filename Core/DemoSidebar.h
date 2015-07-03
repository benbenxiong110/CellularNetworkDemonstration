#pragma once
#include "UIBase.h"

namespace CellularNetworkDemonstration {
    class DemoSidebar : public UIBase {
    public:
        DemoSidebar(SDL_Renderer *renderer)
            :UIBase(renderer, 600, 440) {
            // 设置边栏的显示宽度为195px，分为三级显示
            // 后两级包含返回按钮，每一级别的宽度为
            // 195px，以及5px边框，在转换级别时直接转换
            // 级别的左边坐标即可。
            this->m_pRect->w = 195;



            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);


            //m_pMinimizeIcon = SDL_CreateTexture(m_pRenderer,
            //    SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 11, 10);
            //SDL_SetTextureBlendMode(m_pTexture, SDL_BLENDMODE_BLEND);
            SDL_SetRenderTarget(m_pRenderer, m_pTexture);
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);
            SDL_RenderClear(m_pRenderer);
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            SDL_RenderDrawLine(renderer, 0, 8, 110, 80);
            SDL_RenderDrawLine(renderer, 0, 9, 110, 9);

            int w, h;
            SDL_Color color{ 80, 75, 70, 255 };
            // 界面标题
            m_pTitleText = TTF_RenderTextTexture(renderer, "演示元素", 22, &color);
            SDL_QueryTexture(m_pTitleText, nullptr, nullptr, &w, &h);
            m_pTitleTextRect = new SDL_Rect{ 10, -5, w, h };
            
            // 基站列表标题
            m_pBaseStationListTitle = TTF_RenderTextTexture(renderer, "基站", 16, &color);
            SDL_QueryTexture(m_pBaseStationListTitle, nullptr, nullptr, &w, &h);
            m_pBaseStationListTitleRect = new SDL_Rect{ 15, 26, w, h };

            // 移动台列表标题             
            m_pMobileClientListTitle = TTF_RenderTextTexture(renderer, "移动台", 16, &color);
            SDL_QueryTexture(m_pMobileClientListTitle, nullptr, nullptr, &w, &h);
            m_pMobileClientListTitleRect = new SDL_Rect{ 15, 230, w, h };
            
            // 恢复渲染器状态
            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);


        }

        ~DemoSidebar() {
            // 清理子元素和资源

            //DELETE_IF_EXIST(m_pMenuSystemMinimize)
            //    if (m_pMenuImage) {
            //        SDL_DestroyTexture(m_pMenuImage);
            //    }
            DELETE_IF_EXIST(m_pBaseStationListTitleRect)
            DELETE_IF_EXIST(m_pTitleTextRect)
            DELETE_IF_EXIST(m_pMobileClientListTitleRect)
            if (m_pTitleText) {
                SDL_DestroyTexture(m_pTitleText);
            }            
            if (m_pBaseStationListTitle) {
                SDL_DestroyTexture(m_pBaseStationListTitle);
            }            
            if (m_pMobileClientListTitle) {
                SDL_DestroyTexture(m_pMobileClientListTitle);
            }
        }


    private:
        // 属性

        // 资源
        SDL_Texture *m_pTitleText;
        SDL_Rect *m_pTitleTextRect;
        SDL_Texture *m_pBaseStationListTitle;
        SDL_Rect *m_pBaseStationListTitleRect;
        SDL_Texture *m_pMobileClientListTitle;
        SDL_Rect *m_pMobileClientListTitleRect;
        // 子元素
        //MenuSystemClose *m_pMenuSystemClose;
        //SDL_Rect *m_pMenuSystemCloseRect;


        // 绘制界面元素
        virtual void doRender() {
            SDL_SetRenderDrawColor_DefalutBackground(m_pRenderer);
            SDL_RenderClear(m_pRenderer);
            SDL_RenderCopy(m_pRenderer, m_pTitleText, nullptr, m_pTitleTextRect);
            SDL_RenderCopy(m_pRenderer, m_pBaseStationListTitle, nullptr, m_pBaseStationListTitleRect);
            SDL_RenderCopy(m_pRenderer, m_pMobileClientListTitle, nullptr, m_pMobileClientListTitleRect);
        }

        virtual void doUpdate() {


        }
    };
}