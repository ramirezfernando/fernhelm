#include "Text.h"

Text::Text(const string &fontPath, int fontSize, const string &message, SDL_Color &color)
{
    textTexture = LoadFont(fontPath, fontSize, message, color);
    SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);
}
void Text::Display(int x, int y)
{
    textRect.x = x;
    textRect.y = y;
    SDL_RenderCopy(Game::renderer, textTexture, NULL, &textRect);
}
SDL_Texture *Text::LoadFont(const string &fontPath, int fontSize, const string &message, SDL_Color &color)
{
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font) {
        cout << "Failed to load font" << endl;
    }
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, message.c_str(), color);
    if (!text_surface) {
        cout << "Failed to create text surface" << endl;
    }
    SDL_Texture* text_texture = SDL_CreateTextureFromSurface(Game::renderer, text_surface);
    if (!text_texture) {
        cout << "Failed to create a text texture" << endl;
    }
    SDL_FreeSurface(text_surface);

    return text_texture;
}