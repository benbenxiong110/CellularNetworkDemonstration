#pragma once
#include "Include.h"
#include "UIBase.h"
#include "MenuSystemClose.h"
#include "MenuSystemMinimize.h"
namespace CellularNetworkDemonstration {

    class MenuPanel :public UIBase {
    public:
        MenuPanel(SDL_Renderer *renderer)
            :UIBase(renderer, 800, 150) {
            // 加载资源
            m_pMenuImage = IMG_LoadTexture(m_pRenderer,"menubar.png");

            //初始化子元素
            m_pMenuSystemClose = new MenuSystemClose(m_pRenderer);
            m_pMenuSystemCloseRect = new SDL_Rect();
            m_pMenuSystemCloseRect->x = getWidth() - 50;
            m_pMenuSystemCloseRect->y = 0;
            m_pMenuSystemCloseRect->w = 45;
            m_pMenuSystemCloseRect->h = 20;
            m_pMenuSystemMinimize = new MenuSystemMinimize(m_pRenderer);
            m_pMenuSystemMinimizeRect = new SDL_Rect();
            m_pMenuSystemMinimizeRect->x = getWidth() - 100;
            m_pMenuSystemMinimizeRect->y = 0;
            m_pMenuSystemMinimizeRect->w = 45;
            m_pMenuSystemMinimizeRect->h = 20;

        }

        ~MenuPanel() {
            // 清理子元素和资源

            DELETE_IF_EXIST(m_pMenuSystemMinimize)
            DELETE_IF_EXIST(m_pMenuSystemClose)
            DELETE_IF_EXIST(m_pMenuSystemMinimizeRect)
            DELETE_IF_EXIST(m_pMenuSystemCloseRect)
            if (m_pMenuImage)
            {
                SDL_DestroyTexture(m_pMenuImage);
            }
        }


        int getViewIndex()const {
            return m_iViewIndex;
        }
    private:
        // 属性
        int m_iViewIndex;

        // 资源
        SDL_Texture *m_pMenuImage;

        // 子元素
        MenuSystemClose *m_pMenuSystemClose;
        SDL_Rect *m_pMenuSystemCloseRect;

        MenuSystemMinimize *m_pMenuSystemMinimize;
        SDL_Rect *m_pMenuSystemMinimizeRect;

        // 绘制界面元素
        virtual void doRender() {
            //m_pMenuSystemCloseRect->x = m_sMousePosition.x - m_pMenuSystemCloseRect->w/2;
            //m_pMenuSystemCloseRect->y = m_sMousePosition.y - m_pMenuSystemCloseRect->h / 2;

            SDL_SetRenderDrawColor(m_pRenderer, 20, 120, 220, 255);
            SDL_RenderClear(m_pRenderer);
            SDL_RenderCopy(m_pRenderer, m_pMenuImage, nullptr, nullptr);
            SDL_Texture *closeTexture = m_pMenuSystemClose->render();
            SDL_Texture *minimizeTexture = m_pMenuSystemMinimize->render();
            SDL_RenderCopy(m_pRenderer, closeTexture, m_pMenuSystemClose->Rect(), m_pMenuSystemCloseRect);
            SDL_RenderCopy(m_pRenderer, minimizeTexture, m_pMenuSystemMinimize->Rect(), m_pMenuSystemMinimizeRect);
        }

        virtual void doUpdate() {
            if (SDL_PointInRect(m_sMousePosition, *m_pMenuSystemCloseRect)) {
                m_pMenuSystemClose->update(SDL_RelationPoint(&m_sMousePosition, m_pMenuSystemCloseRect));
            } else {
                m_pMenuSystemClose->update(SDL_Point{ -1, -1 });
            }


            if (SDL_PointInRect(m_sMousePosition, *m_pMenuSystemMinimizeRect)) {
                m_pMenuSystemMinimize->update(SDL_RelationPoint(&m_sMousePosition, m_pMenuSystemMinimizeRect));
            } else {
                m_pMenuSystemMinimize->update(SDL_Point{ -1, -1 });
            }
        }
    };
}
