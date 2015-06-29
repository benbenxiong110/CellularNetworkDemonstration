#pragma once
#include <SDL.h>
#include "Console.h"
#include "MenuPanel.h"

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
                            255, 255, 255, 255);
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
            log("初始化组件...");
            m_pMenuPanel = new MenuPanel(m_pRenderer);

            log("初始化完成");
            m_bRunning = true; 
            return true;
        }
        void render() {
            SDL_Texture* pMenuPanel = m_pMenuPanel->render();
            SDL_SetRenderTarget(m_pRenderer,NULL);
            SDL_RenderClear(m_pRenderer); 
            SDL_RenderCopy(m_pRenderer, pMenuPanel, m_pMenuPanel->Rect(), NULL);
            SDL_RenderPresent(m_pRenderer); 
        }
        void update() {
        }
        void handleEvents() {
            SDL_Event event;
            if (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_QUIT:
                        m_bRunning = false;
                        break;
                    default:
                        break;
                }
            }
        }
        void clean() {
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
    };
}