#pragma once
#include "UIBase.h"
#include "ViewBase.h"

#include "ViewWelcome.h"
#include "ViewIntroduce.h"
#include "ViewDemonstration.h"
#include "ViewAbout.h"

namespace CellularNetworkDemonstration {
    class ViewPanel :
        public UIBase {
    public:
        ViewPanel(SDL_Renderer *renderer)
            :UIBase(renderer, 800, 450) {
            // 初始化子元素
            m_pViews[0] = new ViewWelcome(m_pRenderer, SDL_CHANGEVIEW_01);
            m_pViews[1] = new ViewIntroduce(m_pRenderer, SDL_CHANGEVIEW_02);
            m_pViews[2] = new ViewDemonstration(m_pRenderer, SDL_CHANGEVIEW_03);
            m_pViews[3] = new ViewAbout(m_pRenderer, SDL_CHANGEVIEW_04);
            // 设置属性
            m_iViewIndex = 0;
            m_iViewPreviousIndex = 0;
        }
        ~ViewPanel() {
            // 清理子元素和资源
            for (int i = 0; i < 4; i++) {
                DELETE_IF_EXIST(m_pViews[i])
            }
        }
        void setViewCode(int indexCode) {
            //TODO: Do page changing.
            for (int i = 0; i < 4; i++) {
                if (m_pViews[i]->getViewCode() == indexCode) {
                    this->m_iViewIndex = i;
                    break;
                }
            }
        }

        bool isSwitching() const {
            return m_bSwitching;
        }
    private:
        // 属性
        int m_iViewIndex;
        int m_iViewPreviousIndex;
        bool m_bSwitching;
        // 子元素
        ViewBase *m_pViews[4];

        // 绘制界面元素
        virtual void doRender() {
            
            SDL_Texture* currentView = m_pViews[m_iViewIndex]->render();
            //SDL_SetRenderDrawColor(m_pRenderer, getContiniousValue(4023), getContiniousValue(6732), getContiniousValue(9114), getContiniousValue(7333));
            SDL_RenderClear(m_pRenderer);
            SDL_RenderCopy(m_pRenderer, currentView, NULL, NULL);
        }

        inline int getContiniousValue(int interval) {
            int tick = SDL_GetPerformanceCounter()  / interval % 512;
            if (tick > 255) {
                return 512 - tick;
            } else {
                return tick;
            }
        }

        virtual void update() {
            if (m_bSwitching) {
                m_pViews[m_iViewIndex]->update();
                m_pViews[m_iViewPreviousIndex]->update();

            } else {
                m_pViews[m_iViewIndex]->update(m_sMousePosition);
            }
        }

    };
}


