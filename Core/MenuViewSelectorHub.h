#pragma once
#include "Include.h"
#include "UIBase.h"
#include "MenuViewSelector.h"

namespace CellularNetworkDemonstration {
    class MenuViewSelectorHub : public UIBase {

    public:
        MenuViewSelectorHub(SDL_Renderer *renderer)
            :UIBase(renderer, 400, 30) {
            //初始化子元素
            m_pViewSelectors[0] = new MenuViewSelector(m_pRenderer, "欢迎", SDL_CHANGEVIEW_01);
            m_pViewSelectorRects[0] = new SDL_Rect{ 15, 0, 70, 30 };

            m_pViewSelectors[1] = new MenuViewSelector(m_pRenderer, "介绍", SDL_CHANGEVIEW_02);
            m_pViewSelectorRects[1] = new SDL_Rect{ 115, 0, 70, 30 };

            m_pViewSelectors[2] = new MenuViewSelector(m_pRenderer, "演示", SDL_CHANGEVIEW_03);
            m_pViewSelectorRects[2] = new SDL_Rect{ 215, 0, 70, 30 };

            m_pViewSelectors[3] = new MenuViewSelector(m_pRenderer, "关于", SDL_CHANGEVIEW_04);
            m_pViewSelectorRects[3] = new SDL_Rect{ 315, 0, 70, 30 };


            // 设置属性
            setViewIndex(SDL_CHANGEVIEW_01);
        }
        ~MenuViewSelectorHub() {
            // 清理子元素和资源
            for (int i = 0; i < 4; i++) {
                DELETE_IF_EXIST(m_pViewSelectors[i]);
                DELETE_IF_EXIST(m_pViewSelectorRects[i]);
            }

        }
        inline void setViewIndex(int indexCode) {
            //TODO: Do page changing.
           /* switch (indexCode) {
                default:
                    return;
                    break;
            }*/
            m_iViewCode = indexCode;
            SDL_log("Set index");
            for (int i = 0; i < 4; i++) {
                if (m_pViewSelectors[i]->getSelectorCode() == m_iViewCode) {
                    SDL_log("open");
                    SDL_log(i);
                    m_pViewSelectors[i]->active();
                } else {
                    m_pViewSelectors[i]->deactive();
                }
            }
        }

        inline int getViewIndex() const {
            return m_iViewCode;
        }
    private:
        // 属性
        int m_iViewCode;

        // 子元素
        MenuViewSelector *m_pViewSelectors[4];
        SDL_Rect *m_pViewSelectorRects[4];


        // 绘制界面元素
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);
            SDL_RenderClear(m_pRenderer);
            for (int i = 0; i < 4; i++) {
                SDL_Texture *texture = m_pViewSelectors[i]->render();
                SDL_RenderCopy(m_pRenderer, texture, m_pViewSelectors[i]->Rect(), m_pViewSelectorRects[i]);
            }
        }

        // 
        virtual void doUpdate() {
            for (int i = 0; i < 4; i++) {
                if (SDL_PointInRect(m_sMousePosition, *m_pViewSelectorRects[i])) {
                    m_pViewSelectors[i]->update(SDL_RelationPoint(&m_sMousePosition, m_pViewSelectorRects[i]));
                } else {
                    m_pViewSelectors[i]->update(SDL_Point{ -1, -1 });
                }
            }
        }
    };
}