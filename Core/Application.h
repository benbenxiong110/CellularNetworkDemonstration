#pragma once
#include <SDL.h>
#include "Console.h"
#include "MenuPanel.h"
#include "ViewPanel.h"
#include "MouseManager.h"

namespace CellularNetworkDemonstration {

    const static char* ApplaicationName = "Cellular Network Demo";

    class Application {
    public:
        Application();
        ~Application();

        bool init() {
            // 初始化程序
            log("初始化程序...");
            if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
                // 建立窗口
                log("建立窗口");
                m_pWindow = SDL_CreateWindow(ApplaicationName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                    800, 600, SDL_WINDOW_BORDERLESS);
                if (m_pWindow != 0) {
                    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
                    if (m_pRenderer != 0) {
                        SDL_SetRenderDrawColor(m_pRenderer,
                            210, 210, 210, 255);
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
            log("初始化组件...");
            m_pMenuPanel = new MenuPanel(m_pRenderer);
            m_pMenuPanelRect = new SDL_Rect();
            m_pMenuPanelRect->x = 0;
            m_pMenuPanelRect->y = 0;
            m_pMenuPanelRect->w = 800;
            m_pMenuPanelRect->h = 150;
            m_pViewPanel = new ViewPanel(m_pRenderer);
            m_pViewPanelRect = new SDL_Rect();
            m_pViewPanelRect->x = 0;
            m_pViewPanelRect->y = 150;
            m_pViewPanelRect->w = 800;
            m_pViewPanelRect->h = 450;

            log("初始化完成");
            m_bRunning = true;
            return true;
        }
        void render() {
            static long last;
            static long now;
            now = SDL_GetTicks();
            SDL_Delay(20);
            if (now - last > 1000 / 60) {
                if (now - last > 100) {
                    log("Low Performance!!!");
                    log(now - last);
                }
                last = now;
                SDL_Texture* pMenuPanel = m_pMenuPanel->render();
                SDL_Texture* pViewPanel = m_pViewPanel->render();
                SDL_RenderClear(m_pRenderer);
                SDL_RenderCopy(m_pRenderer, pMenuPanel, m_pMenuPanel->Rect(), m_pMenuPanelRect);
                SDL_RenderCopy(m_pRenderer, pViewPanel, m_pViewPanel->Rect(), m_pViewPanelRect);
                SDL_RenderPresent(m_pRenderer);
            }

        }
        void update() {
            //log("Update Application");
        }
        void handleEvents() {
            //log("Handle Events");
            SDL_Event event;
            if (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        m_bRunning = false;
                        break;
                    case SDL_MOUSEBUTTONUP:
                        MouseManager::get().OnMouseButtonUp(event);
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        MouseManager::get().OnMouseButtonDown(event);
                        break;
                    case SDL_MOUSEMOTION:
                        MouseManager::get().OnMouseMotion(event);
                        break;
                    case SDL_MOUSEWHEEL:
                        MouseManager::get().OnMouseWheel(event);

                    default:
                        break;
                }
            }
        }
        void clean() {
            delete  m_pMenuPanel;
            delete m_pMenuPanelRect;
            delete m_pViewPanel;
            delete m_pViewPanelRect;

            SDL_DestroyWindow(m_pWindow);
            SDL_DestroyRenderer(m_pRenderer);
            SDL_Quit();
        }

        inline bool running() const {
            return m_bRunning;
        }
    private:
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
        bool m_bRunning;

        MenuPanel* m_pMenuPanel;
        SDL_Rect* m_pMenuPanelRect;
        ViewPanel* m_pViewPanel;
        SDL_Rect* m_pViewPanelRect;
    };
}