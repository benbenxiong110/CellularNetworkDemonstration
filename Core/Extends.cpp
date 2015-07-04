#include "Extends.h"
#include <Windows.h>


namespace CellularNetworkDemonstration {
    char *localeToUTF8(const char *src) {
        static char *buf = NULL;
        if (buf) {
            free(buf);
            buf = NULL;
        }
        wchar_t *unicode_buf;
        int nRetLen = MultiByteToWideChar(CP_ACP, 0, src, -1, NULL, 0);
        unicode_buf = ( wchar_t* ) malloc(( nRetLen + 1 )*sizeof(wchar_t));
        MultiByteToWideChar(CP_ACP, 0, src, -1, unicode_buf, nRetLen);
        nRetLen = WideCharToMultiByte(CP_UTF8, 0, unicode_buf, -1, NULL, 0, NULL, NULL);
        buf = ( char* ) malloc(nRetLen + 1);
        WideCharToMultiByte(CP_UTF8, 0, unicode_buf, -1, buf, nRetLen, NULL, NULL);
        free(unicode_buf);
        return buf;
    }

    SDL_Texture * TTF_RenderTextTexture(SDL_Renderer *renderer, const std::string &message, int fontSize, SDL_Color *color /*= nullptr*/, TTF_FontFamilySeries fontFamily /*= TTF_FONT_DEFAULT*/) {
    const static SDL_Color defaultColor{ 255, 255, 255, 255 };
    const static char* fontDir = SDL_getenv("WinDir");
    const static char* fontSansSerif = "\\Fonts\\msyh.ttc";
    const static char* fontSerif = "\\Fonts\\SimSun.ttc";
    const static char* fontMonospace = "\\Fonts\\consolas.ttf";
    std::string fontFile = fontDir;
    switch (fontFamily) {
        case CellularNetworkDemonstration::TTF_FONT_SANS_SERIF:
            fontFile += fontSansSerif;
            break;
        case CellularNetworkDemonstration::TTF_FONT_SERIF:
            fontFile += fontSerif;
            break;
        case CellularNetworkDemonstration::TTF_FONT_MONOSPACE:
            fontFile += fontMonospace;
            break;
        default:
            break;
    }
    // 打开字体文件
    TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr) {
        SDL_log("字体文件打开失败");
        return nullptr;
    }
    //We need to first render to a surface as that's what TTF_RenderText returns, then
    //load that surface into a texture
    //wchar_t *wMessage = new wchar_t[message.size() + 1];
    //size_t cov;
    //mbstowcs_s(&cov, wMessage, message.size() + 1, message.c_str(), message.size());
    SDL_Surface *surf = TTF_RenderUTF8_Blended(font, localeToUTF8(message.c_str()), color ? *color : defaultColor);
    //delete wMessage;
    if (surf == nullptr) {
        TTF_CloseFont(font);
        SDL_log("字体渲染失败");
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr) {
        SDL_log("字体表面转换失败");
    }
    //Clean up the surface and font
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}

}