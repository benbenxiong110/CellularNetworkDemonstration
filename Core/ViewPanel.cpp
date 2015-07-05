#include "ViewPanel.h"
namespace CellularNetworkDemonstration {

    ViewPanel::ViewPanel(SDL_Renderer *renderer) :UIBase(renderer, 800, 450) {
        // 初始化子元素
        m_pViews[0] = new ViewWelcome(m_pRenderer, SDL_CHANGEVIEW_01);
        m_pViews[1] = new ViewIntroduce(m_pRenderer, SDL_CHANGEVIEW_02);
        m_pViews[2] = new ViewDemonstration(m_pRenderer, SDL_CHANGEVIEW_03);
        m_pViews[3] = new ViewAbout(m_pRenderer, SDL_CHANGEVIEW_04);
        // 设置属性
        m_iViewIndex = 0;
        m_iViewPreviousIndex = 0;
        m_bSwitching = false;
    }

    ViewPanel::~ViewPanel() {
        // 清理子元素和资源
        for (int i = 0; i < 4; i++) {
            DELETE_IF_EXIST(m_pViews[i])
        }
    }

    void ViewPanel::setViewCode(int indexCode) {
        //TODO: Do page changing.
        for (int i = 0; i < 4; i++) {
            if (m_pViews[i]->getViewCode() == indexCode) {
                this->m_iViewIndex = i;
                break;
            }
        }
    }

    bool ViewPanel::handleEvents(SDL_Event &event) {
        return this->m_pViews[2]->handleEvents(event);
    }

    bool ViewPanel::isSwitching() const {
        return m_bSwitching;
    }

    void ViewPanel::doRender() {
        SDL_Texture* currentView = m_pViews[m_iViewIndex]->render();
        //SDL_SetRenderDrawColor(m_pRenderer, getContiniousValue(4023), getContiniousValue(6732), getContiniousValue(9114), getContiniousValue(7333));
        //SDL_SetRenderDrawColor_DefalutBackground(m_pRenderer);
        SDL_RenderClear(m_pRenderer);
        SDL_RenderCopy(m_pRenderer, currentView, m_pViews[m_iViewIndex]->Rect(), NULL);
    }

    int ViewPanel::getContiniousValue(int interval) {
        int tick = SDL_GetPerformanceCounter() / interval % 512;
        if (tick > 255) {
            return 512 - tick;
        } else {
            return tick;
        }
    }

    void ViewPanel::doUpdate() {
        if (m_bSwitching) {
            m_pViews[m_iViewIndex]->update();
            m_pViews[m_iViewPreviousIndex]->update();

        } else {
            m_pViews[m_iViewIndex]->update(m_sMousePosition);
        }
    }

}

