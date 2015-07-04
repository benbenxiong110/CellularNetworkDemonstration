#pragma once
#include "Include.h"

namespace CellularNetworkDemonstration {
    class DemoTextureManager {
    public:
        static DemoTextureManager &get() {
            static DemoTextureManager* instance = nullptr;
            if (instance == nullptr) {
                instance = new DemoTextureManager();
            }
            return *instance;
        }
        SDL_Texture* getTexture(SDL_Renderer *renderer, string textureName) {
            map<string, SDL_Texture*>::iterator name = textureMap.find(textureName);
            if (name == textureMap.end()) {
                textureMap.insert(pair<string, SDL_Texture*>(textureName, IMG_LoadTexture(renderer, textureName.c_str())));
            }
            return textureMap[textureName];
        }
    private:
        DemoTextureManager() {

        }
        ~DemoTextureManager() {

        }
        map<string, SDL_Texture*> textureMap;

    };
}